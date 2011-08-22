/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkGreyLevelRunLengthMatrixTextureCoefficientsCalculatorTest.cxx,v $
  Language:  C++
  Date:      $Date: $
  Version:   $Revision: $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "itkBoundingBox.h"
#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageRegionIteratorWithIndex.h"
#include "itkPointSet.h"

#include "itkScalarImageToRunLengthFeaturesFilter.h"
#include "itkDenseFrequencyContainer2.h"

int itkRunLengthFeaturesTest( int argc, char* argv[] )
{
  const unsigned int ImageDimension = 3;
  typedef float PixelType;
  typedef float RealType;

  typedef itk::Image<PixelType, ImageDimension> ImageType;
  typedef itk::Image<RealType, ImageDimension> RealImageType;

  typedef itk::ImageFileReader<ImageType> ReaderType;
  ReaderType::Pointer imageReader = ReaderType::New();
  imageReader->SetFileName( argv[1] );
  imageReader->Update();

  typedef itk::Statistics::DenseFrequencyContainer2 HistogramFrequencyContainerType;

  typedef itk::Statistics::ScalarImageToRunLengthFeaturesFilter
    <RealImageType, HistogramFrequencyContainerType> RunLengthFilterType;
  RunLengthFilterType::Pointer runLengthFilter = RunLengthFilterType::New();
  runLengthFilter->SetInput( imageReader->GetOutput() );

  ImageType::Pointer mask = NULL;
  PixelType label = itk::NumericTraits<PixelType>::One;
  if ( argc > 3 )
    {
    ReaderType::Pointer labelImageReader = ReaderType::New();
    labelImageReader->SetFileName( argv[3] );
    labelImageReader->Update();
    mask = labelImageReader->GetOutput();
    runLengthFilter->SetInput( mask );

    if ( argc > 4 )
      {
      label = static_cast<PixelType>( atoi( argv[4] ) );
      }
    runLengthFilter->SetInsidePixelValue( label );
    }


  unsigned int numberOfBins = 256;
  if ( argc > 2 )
    {
    numberOfBins = static_cast<PixelType>( atoi( argv[2] ) );
    }
  runLengthFilter->SetNumberOfBinsPerAxis( numberOfBins );


  itk::ImageRegionIteratorWithIndex<ImageType> ItI( imageReader->GetOutput(),
    imageReader->GetOutput()->GetLargestPossibleRegion() );

  PixelType maxValue = itk::NumericTraits<PixelType>::NonpositiveMin();
  PixelType minValue = itk::NumericTraits<PixelType>::max();

  typedef itk::BoundingBox<unsigned long,
       ImageDimension, RealType> BoundingBoxType;
  BoundingBoxType::Pointer bbox = BoundingBoxType::New();
  BoundingBoxType::PointsContainerPointer points
       = BoundingBoxType::PointsContainer::New();
  itk::Point<RealType, ImageDimension> point;

  unsigned int idx = 0;

  for( ItI.GoToBegin(); !ItI.IsAtEnd(); ++ItI )
    {
    if ( !mask || ( mask->GetPixel( ItI.GetIndex() ) == label ) )
      {
      if ( ItI.Get() < minValue )
        {
        minValue = ItI.Get();
        }
      else if ( ItI.Get() > maxValue )
        {
        maxValue = ItI.Get();
        }
      imageReader->GetOutput()->TransformIndexToPhysicalPoint( ItI.GetIndex(), point );
      points->InsertElement( idx++, point );
      }
    }
  bbox->SetPoints( points );
  bbox->ComputeBoundingBox();
  BoundingBoxType::PointType pointMin = bbox->GetMinimum();
  BoundingBoxType::PointType pointMax = bbox->GetMaximum();

  runLengthFilter->SetPixelValueMinMax( minValue, maxValue );
  runLengthFilter->SetDistanceValueMinMax( 0, pointMin.EuclideanDistanceTo( pointMax ) );
  runLengthFilter->SetNumberOfBinsPerAxis( numberOfBins );
  runLengthFilter->FastCalculationsOff();

  try
    {
    runLengthFilter->Update();

    RunLengthFilterType::FeatureValueVectorPointer means =
      runLengthFilter->GetFeatureMeans();
    const RunLengthFilterType::FeatureNameVector* names =
      runLengthFilter->GetRequestedFeatures();

    RunLengthFilterType::FeatureValueVector::ConstIterator mIt =
      means->Begin();
    RunLengthFilterType::FeatureNameVector::ConstIterator nIt =
      names->Begin();

    std::cout << "ShortRunEmphasis,LongRunEmphasis,GreyLevelNonuniformity,RunLengthNonuniformity,LowGreyLevelRunEmphasis,HighGreyLevelRunEmphasis,ShortRunLowGreyLevelEmphasis,ShortRunHighGreyLevelEmphasis,LongRunLowGreyLevelEmphasis,LongRunHighGreyLevelEmphasis" << std::endl;
    while( mIt != means->End() )
      {
  //    std::cout << nIt.Value() << ": " << mIt.Value() << std::endl;
      std::cout << mIt.Value() << " ";
      ++mIt;
      ++nIt;
      }
    std::cout << std::endl;

    return EXIT_SUCCESS;
    }
  catch(...)
   {
   return EXIT_FAILURE;
   }
}

int main( int argc, char *argv[] )
{
  if ( argc < 2 )
    {
    std::cout << "Usage: " << argv[0] << " inputImage " << std::endl;
    return EXIT_FAILURE;
    }

  return itkRunLengthFeaturesTest( argc, argv );
}
