vtk_module(vtkIOInfovis
  GROUPS
    StandAlone
  DEPENDS
    vtkCommonDataModel
    vtkCommonSystem
    vtkCommonMisc
    vtkIOCore
    vtkIOLegacy
    vtkIOXML
    vtkInfovisCore
  PRIVATE_DEPENDS
    vtklibxml2
    vtksys
  TEST_DEPENDS
    vtkInfovisLayout
    vtkRenderingCore
    vtkTestingRendering
  )
