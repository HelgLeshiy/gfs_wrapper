:: GFS. Debug build script
::
:: FILE      build_debug.bat
:: AUTHOR    Ilya Akkuzin <gr3yknigh1@gmail.com>
:: COPYRIGHT (c) 2024 Ilya Akkuzin

@echo off


set vc2022_bootstrap="C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat"
set vc2019_bootstrap="C:\Program Files (x86)\Microsoft Visual Studio\2019\Preview\VC\Auxiliary\Build\vcvarsall.bat"

if exist %vc2022_bootstrap% (
  echo I: Found VC 2022 boostrap script!
		call %vc2022_bootstrap% amd64
) else (

  if exist %vc2019_bootstrap% (
    echo I: VC 2022 script not found. Only VC 2019 script was found.
    call %vc2019_boostrap% amd64
  ) else (
    echo W: Failed to find boostrap scripts of 2019 or 2022 VC :c
  )
)

set project_path=%~dp0
pushd %project_path%

set configuration_path=%project_path%\Build

if exist %configuration_path%\ (
  echo I: Debug configuration already exists!
) else (
  echo I: Debug configuration not found. Generating new one!
  cmake -S %project_path% -B %configuration_path% -S %project_path% -D CMAKE_EXPORT_COMPILE_COMMANDS=1
)

cmake --build %configuration_path%

popd
