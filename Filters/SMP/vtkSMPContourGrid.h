/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkSMPContourGrid.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMPContourGrid - a subclass of vtkContourGrid that works in parallel
// vtkSMPContourGrid performs the same functionaliy as vtkContourGrid but does
// it using multiple threads. This will probably be merged with vtkContourGrid
// in the future.

#ifndef vtkSMPContourGrid_h
#define vtkSMPContourGrid_h

#include "vtkFiltersSMPModule.h" // For export macro
#include "vtkContourGrid.h"

class VTKFILTERSSMP_EXPORT vtkSMPContourGrid : public vtkContourGrid
{
public:
  vtkTypeMacro(vtkSMPContourGrid,vtkContourGrid);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Constructor.
  static vtkSMPContourGrid *New();

  // Description:
  // If MergePieces is true (default), this filter will merge all
  // pieces generated by processing the input with multiple threads.
  // The output will be a vtkPolyData. Note that this has a slight overhead
  // which becomes more significant as the number of threads used grows.
  // If MergePieces is false, this filter will generate a vtkMultiBlock
  // of vtkPolyData where the number of pieces will be equal to the number
  // of threads used.
  vtkSetMacro(MergePieces, bool);
  vtkGetMacro(MergePieces, bool);
  vtkBooleanMacro(MergePieces, bool);

  // Description:
  // see vtkAlgorithm for details
  virtual int ProcessRequest(vtkInformation*,
                             vtkInformationVector**,
                             vtkInformationVector*);

protected:
  vtkSMPContourGrid();
  ~vtkSMPContourGrid();

  virtual int RequestDataObject(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

  virtual int FillOutputPortInformation(int port, vtkInformation* info);

  bool MergePieces;

private:
  vtkSMPContourGrid(const vtkSMPContourGrid&);  // Not implemented.
  void operator=(const vtkSMPContourGrid&);  // Not implemented.
};

#endif
