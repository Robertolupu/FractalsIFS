##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=IFS
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Usuario/Documents/GitHub/FractalsIFS
ProjectPath            :=C:/Users/Usuario/Documents/GitHub/FractalsIFS/IFS
IntermediateDirectory  :=../Builds
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Usuario
Date                   :=04/02/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/Programs/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="IFS.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_ifs.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\Usuario\Documents\GitHub\FractalsIFS/.build-debug"
	@echo rebuilt > "C:\Users\Usuario\Documents\GitHub\FractalsIFS/.build-debug/IFS"

MakeIntermediateDirs:
	@$(MakeDirCommand) "../Builds"


../Builds:
	@$(MakeDirCommand) "../Builds"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_ifs.cpp$(ObjectSuffix): src/ifs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ifs.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ifs.cpp$(DependSuffix) -MM src/ifs.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Usuario/Documents/GitHub/FractalsIFS/IFS/src/ifs.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ifs.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ifs.cpp$(PreprocessSuffix): src/ifs.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ifs.cpp$(PreprocessSuffix) src/ifs.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../Builds/


