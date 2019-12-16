##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=IFS
ConfigurationName      :=Debug
WorkspacePath          :=/home/roberto/Documents/FractalsIFS
ProjectPath            :=/home/roberto/Documents/FractalsIFS/IFS
IntermediateDirectory  :=../Builds
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Roberto
Date                   :=16/12/19
CodeLitePath           :=/home/roberto/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_transformation.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "/home/roberto/Documents/FractalsIFS/.build-debug"
	@echo rebuilt > "/home/roberto/Documents/FractalsIFS/.build-debug/IFS"

MakeIntermediateDirs:
	@test -d ../Builds || $(MakeDirCommand) ../Builds


../Builds:
	@test -d ../Builds || $(MakeDirCommand) ../Builds

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_transformation.cpp$(ObjectSuffix): src/transformation.cpp $(IntermediateDirectory)/src_transformation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/roberto/Documents/FractalsIFS/IFS/src/transformation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_transformation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_transformation.cpp$(DependSuffix): src/transformation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_transformation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_transformation.cpp$(DependSuffix) -MM src/transformation.cpp

$(IntermediateDirectory)/src_transformation.cpp$(PreprocessSuffix): src/transformation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_transformation.cpp$(PreprocessSuffix) src/transformation.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../Builds/


