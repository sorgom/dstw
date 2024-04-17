# Alternative GNU Make project makefile autogenerated by Premake

ifndef config
  config=ci
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq ($(shell echo "test"), "test")
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
DEFINES += -DNDEBUG -DCPPUTEST_USE_LONG_LONG=0
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES)
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -std=c++17 -pedantic-errors -Werror -Wall
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -std=c++17 -pedantic-errors -Werror -Wall
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
LIBS += -lCppUTest -lCppUTestExt
LDDEPS +=
ALL_LDFLAGS += $(LDFLAGS) -L../BuildCppUTest/lib -s
LINKCMD = $(CXX) -o "$@" $(OBJECTS) $(RESOURCES) $(ALL_LDFLAGS) $(LIBS)
define PRELINKCMDS
endef

ifeq ($(config),ci)
TARGETDIR = bin
TARGET = $(TARGETDIR)/tests_ci
OBJDIR = obj/gcc/tests/ci
INCLUDES += -I../testing/testenv -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components
define PREBUILDCMDS
endef
define POSTBUILDCMDS
endef

else ifeq ($(config),qnd)
TARGETDIR = bin
TARGET = $(TARGETDIR)/tests_qnd
OBJDIR = obj/gcc/tests/qnd
INCLUDES += -I../testing/testenv -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components -I../devel
define PREBUILDCMDS
endef
define POSTBUILDCMDS
endef

else ifeq ($(config),mod)
TARGETDIR = bin
TARGET = $(TARGETDIR)/tests_mod
OBJDIR = obj/gcc/tests/mod
INCLUDES += -I../testing/testenv -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components
define PREBUILDCMDS
endef
define POSTBUILDCMDS
endef

else ifeq ($(config),sys)
TARGETDIR = bin
TARGET = $(TARGETDIR)/tests_sys
OBJDIR = obj/gcc/tests/sys
INCLUDES += -I../testing/testenv -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components
define PREBUILDCMDS
endef
define POSTBUILDCMDS
endef

else ifeq ($(config),dev)
TARGETDIR = bin
TARGET = $(TARGETDIR)/tests_dev
OBJDIR = obj/gcc/tests/dev
INCLUDES += -I../testing/testenv -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components
define PREBUILDCMDS
endef
define POSTBUILDCMDS
endef

else ifeq ($(config),bullseye)
TARGETDIR = bin
TARGET = $(TARGETDIR)/tests_bullseye
OBJDIR = obj/gcc/tests/bullseye
INCLUDES += -I../testing/testenv -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components
define PREBUILDCMDS
	@echo Running prebuild commands
	cov01 -1 --no-banner
endef
define POSTBUILDCMDS
	@echo Running postbuild commands
	./bullseye.sh
endef

else ifeq ($(config),tmp)
TARGETDIR = bin
TARGET = $(TARGETDIR)/tests_tmp
OBJDIR = obj/gcc/tests/tmp
INCLUDES += -I../testing/testenv -I../BuildCppUTest/CppUTest/include -I../CppUTestSteps/TestSteps/include -I../specification -I../application -I../application/components -I../devel
define PREBUILDCMDS
endef
define POSTBUILDCMDS
endef

endif

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/BAS_Provider.o
GENERATED += $(OBJDIR)/Com.o
GENERATED += $(OBJDIR)/Comparator.o
GENERATED += $(OBJDIR)/Dispatcher.o
GENERATED += $(OBJDIR)/IL.o
GENERATED += $(OBJDIR)/LCR_Provider.o
GENERATED += $(OBJDIR)/LCR_X.o
GENERATED += $(OBJDIR)/Log.o
GENERATED += $(OBJDIR)/M_Instances.o
GENERATED += $(OBJDIR)/Reader.o
GENERATED += $(OBJDIR)/SIG_Provider.o
GENERATED += $(OBJDIR)/SIG_X.o
GENERATED += $(OBJDIR)/TSW.o
GENERATED += $(OBJDIR)/TSW_Provider.o
GENERATED += $(OBJDIR)/TestGroupBase.o
GENERATED += $(OBJDIR)/TestLib.o
GENERATED += $(OBJDIR)/TestLiterals.o
GENERATED += $(OBJDIR)/TestMain.o
GENERATED += $(OBJDIR)/TestSteps.o
GENERATED += $(OBJDIR)/TestStepsPlugin.o
GENERATED += $(OBJDIR)/installComparators.o
GENERATED += $(OBJDIR)/ostreamHelpers.o
GENERATED += $(OBJDIR)/ostreams.o
OBJECTS += $(OBJDIR)/BAS_Provider.o
OBJECTS += $(OBJDIR)/Com.o
OBJECTS += $(OBJDIR)/Comparator.o
OBJECTS += $(OBJDIR)/Dispatcher.o
OBJECTS += $(OBJDIR)/IL.o
OBJECTS += $(OBJDIR)/LCR_Provider.o
OBJECTS += $(OBJDIR)/LCR_X.o
OBJECTS += $(OBJDIR)/Log.o
OBJECTS += $(OBJDIR)/M_Instances.o
OBJECTS += $(OBJDIR)/Reader.o
OBJECTS += $(OBJDIR)/SIG_Provider.o
OBJECTS += $(OBJDIR)/SIG_X.o
OBJECTS += $(OBJDIR)/TSW.o
OBJECTS += $(OBJDIR)/TSW_Provider.o
OBJECTS += $(OBJDIR)/TestGroupBase.o
OBJECTS += $(OBJDIR)/TestLib.o
OBJECTS += $(OBJDIR)/TestLiterals.o
OBJECTS += $(OBJDIR)/TestMain.o
OBJECTS += $(OBJDIR)/TestSteps.o
OBJECTS += $(OBJDIR)/TestStepsPlugin.o
OBJECTS += $(OBJDIR)/installComparators.o
OBJECTS += $(OBJDIR)/ostreamHelpers.o
OBJECTS += $(OBJDIR)/ostreams.o

ifeq ($(config),ci)
GENERATED += $(OBJDIR)/BAS_01.o
GENERATED += $(OBJDIR)/BAS_02.o
GENERATED += $(OBJDIR)/LCR_01.o
GENERATED += $(OBJDIR)/LCR_02.o
GENERATED += $(OBJDIR)/LCR_03.o
GENERATED += $(OBJDIR)/SIG_01.o
GENERATED += $(OBJDIR)/SIG_02.o
GENERATED += $(OBJDIR)/SIG_03.o
GENERATED += $(OBJDIR)/SYST_01.o
GENERATED += $(OBJDIR)/SYST_02.o
GENERATED += $(OBJDIR)/SYS_01.o
GENERATED += $(OBJDIR)/SYS_02.o
GENERATED += $(OBJDIR)/SYS_03.o
GENERATED += $(OBJDIR)/TSW_01.o
GENERATED += $(OBJDIR)/TSW_02.o
GENERATED += $(OBJDIR)/TSW_03.o
OBJECTS += $(OBJDIR)/BAS_01.o
OBJECTS += $(OBJDIR)/BAS_02.o
OBJECTS += $(OBJDIR)/LCR_01.o
OBJECTS += $(OBJDIR)/LCR_02.o
OBJECTS += $(OBJDIR)/LCR_03.o
OBJECTS += $(OBJDIR)/SIG_01.o
OBJECTS += $(OBJDIR)/SIG_02.o
OBJECTS += $(OBJDIR)/SIG_03.o
OBJECTS += $(OBJDIR)/SYST_01.o
OBJECTS += $(OBJDIR)/SYST_02.o
OBJECTS += $(OBJDIR)/SYS_01.o
OBJECTS += $(OBJDIR)/SYS_02.o
OBJECTS += $(OBJDIR)/SYS_03.o
OBJECTS += $(OBJDIR)/TSW_01.o
OBJECTS += $(OBJDIR)/TSW_02.o
OBJECTS += $(OBJDIR)/TSW_03.o

else ifeq ($(config),qnd)
GENERATED += $(OBJDIR)/BAS_01.o
GENERATED += $(OBJDIR)/BAS_02.o
GENERATED += $(OBJDIR)/LCR_01.o
GENERATED += $(OBJDIR)/LCR_02.o
GENERATED += $(OBJDIR)/LCR_03.o
GENERATED += $(OBJDIR)/SIG_01.o
GENERATED += $(OBJDIR)/SIG_02.o
GENERATED += $(OBJDIR)/SIG_03.o
GENERATED += $(OBJDIR)/SYST_01.o
GENERATED += $(OBJDIR)/SYST_02.o
GENERATED += $(OBJDIR)/SYS_01.o
GENERATED += $(OBJDIR)/SYS_02.o
GENERATED += $(OBJDIR)/SYS_03.o
GENERATED += $(OBJDIR)/TSW_01.o
GENERATED += $(OBJDIR)/TSW_02.o
GENERATED += $(OBJDIR)/TSW_03.o
OBJECTS += $(OBJDIR)/BAS_01.o
OBJECTS += $(OBJDIR)/BAS_02.o
OBJECTS += $(OBJDIR)/LCR_01.o
OBJECTS += $(OBJDIR)/LCR_02.o
OBJECTS += $(OBJDIR)/LCR_03.o
OBJECTS += $(OBJDIR)/SIG_01.o
OBJECTS += $(OBJDIR)/SIG_02.o
OBJECTS += $(OBJDIR)/SIG_03.o
OBJECTS += $(OBJDIR)/SYST_01.o
OBJECTS += $(OBJDIR)/SYST_02.o
OBJECTS += $(OBJDIR)/SYS_01.o
OBJECTS += $(OBJDIR)/SYS_02.o
OBJECTS += $(OBJDIR)/SYS_03.o
OBJECTS += $(OBJDIR)/TSW_01.o
OBJECTS += $(OBJDIR)/TSW_02.o
OBJECTS += $(OBJDIR)/TSW_03.o

else ifeq ($(config),mod)
GENERATED += $(OBJDIR)/BAS_01.o
GENERATED += $(OBJDIR)/BAS_02.o
GENERATED += $(OBJDIR)/LCR_01.o
GENERATED += $(OBJDIR)/LCR_02.o
GENERATED += $(OBJDIR)/LCR_03.o
GENERATED += $(OBJDIR)/SIG_01.o
GENERATED += $(OBJDIR)/SIG_02.o
GENERATED += $(OBJDIR)/SIG_03.o
GENERATED += $(OBJDIR)/SYS_01.o
GENERATED += $(OBJDIR)/SYS_02.o
GENERATED += $(OBJDIR)/SYS_03.o
GENERATED += $(OBJDIR)/TSW_01.o
GENERATED += $(OBJDIR)/TSW_02.o
GENERATED += $(OBJDIR)/TSW_03.o
OBJECTS += $(OBJDIR)/BAS_01.o
OBJECTS += $(OBJDIR)/BAS_02.o
OBJECTS += $(OBJDIR)/LCR_01.o
OBJECTS += $(OBJDIR)/LCR_02.o
OBJECTS += $(OBJDIR)/LCR_03.o
OBJECTS += $(OBJDIR)/SIG_01.o
OBJECTS += $(OBJDIR)/SIG_02.o
OBJECTS += $(OBJDIR)/SIG_03.o
OBJECTS += $(OBJDIR)/SYS_01.o
OBJECTS += $(OBJDIR)/SYS_02.o
OBJECTS += $(OBJDIR)/SYS_03.o
OBJECTS += $(OBJDIR)/TSW_01.o
OBJECTS += $(OBJDIR)/TSW_02.o
OBJECTS += $(OBJDIR)/TSW_03.o

else ifeq ($(config),sys)
GENERATED += $(OBJDIR)/SYST_01.o
GENERATED += $(OBJDIR)/SYST_02.o
OBJECTS += $(OBJDIR)/SYST_01.o
OBJECTS += $(OBJDIR)/SYST_02.o

else ifeq ($(config),dev)
GENERATED += $(OBJDIR)/DT_01.o
GENERATED += $(OBJDIR)/DT_02.o
GENERATED += $(OBJDIR)/DT_03.o
OBJECTS += $(OBJDIR)/DT_01.o
OBJECTS += $(OBJDIR)/DT_02.o
OBJECTS += $(OBJDIR)/DT_03.o

else ifeq ($(config),bullseye)
GENERATED += $(OBJDIR)/BAS_01.o
GENERATED += $(OBJDIR)/BAS_02.o
GENERATED += $(OBJDIR)/LCR_01.o
GENERATED += $(OBJDIR)/LCR_02.o
GENERATED += $(OBJDIR)/LCR_03.o
GENERATED += $(OBJDIR)/SIG_01.o
GENERATED += $(OBJDIR)/SIG_02.o
GENERATED += $(OBJDIR)/SIG_03.o
GENERATED += $(OBJDIR)/SYS_01.o
GENERATED += $(OBJDIR)/SYS_02.o
GENERATED += $(OBJDIR)/SYS_03.o
GENERATED += $(OBJDIR)/TSW_01.o
GENERATED += $(OBJDIR)/TSW_02.o
GENERATED += $(OBJDIR)/TSW_03.o
OBJECTS += $(OBJDIR)/BAS_01.o
OBJECTS += $(OBJDIR)/BAS_02.o
OBJECTS += $(OBJDIR)/LCR_01.o
OBJECTS += $(OBJDIR)/LCR_02.o
OBJECTS += $(OBJDIR)/LCR_03.o
OBJECTS += $(OBJDIR)/SIG_01.o
OBJECTS += $(OBJDIR)/SIG_02.o
OBJECTS += $(OBJDIR)/SIG_03.o
OBJECTS += $(OBJDIR)/SYS_01.o
OBJECTS += $(OBJDIR)/SYS_02.o
OBJECTS += $(OBJDIR)/SYS_03.o
OBJECTS += $(OBJDIR)/TSW_01.o
OBJECTS += $(OBJDIR)/TSW_02.o
OBJECTS += $(OBJDIR)/TSW_03.o

else ifeq ($(config),tmp)
GENERATED += $(OBJDIR)/TSW_01.o
OBJECTS += $(OBJDIR)/TSW_01.o

endif

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking tests
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning tests
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) del /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif


# File Rules
# #############################################

$(OBJDIR)/TestSteps.o: ../CppUTestSteps/TestSteps/src/TestSteps.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestStepsPlugin.o: ../CppUTestSteps/TestSteps/src/TestStepsPlugin.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/BAS_Provider.o: ../application/components/BAS/src/BAS_Provider.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_Provider.o: ../application/components/LCR/src/LCR_Provider.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_X.o: ../application/components/LCR/src/LCR_X.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_Provider.o: ../application/components/SIG/src/SIG_Provider.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_X.o: ../application/components/SIG/src/SIG_X.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Com.o: ../application/components/SYS/src/Com.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Dispatcher.o: ../application/components/SYS/src/Dispatcher.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Log.o: ../application/components/SYS/src/Log.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Reader.o: ../application/components/SYS/src/Reader.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW.o: ../application/components/TSW/src/TSW.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_Provider.o: ../application/components/TSW/src/TSW_Provider.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/IL.o: ../testing/testenv/SYS/src/IL.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/Comparator.o: ../testing/testenv/comparators/src/Comparator.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/installComparators.o: ../testing/testenv/comparators/src/installComparators.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/ostreamHelpers.o: ../testing/testenv/comparators/src/ostreamHelpers.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/ostreams.o: ../testing/testenv/comparators/src/ostreams.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/M_Instances.o: ../testing/testenv/mocks/src/M_Instances.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestGroupBase.o: ../testing/testenv/testlib/src/TestGroupBase.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestLib.o: ../testing/testenv/testlib/src/TestLib.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestLiterals.o: ../testing/testenv/testlib/src/TestLiterals.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TestMain.o: ../testing/testenv/testlib/src/TestMain.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

ifeq ($(config),ci)
$(OBJDIR)/BAS_01.o: ../testing/tests/moduletests/BAS/BAS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/BAS_02.o: ../testing/tests/moduletests/BAS/BAS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_01.o: ../testing/tests/moduletests/LCR/LCR_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_02.o: ../testing/tests/moduletests/LCR/LCR_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_03.o: ../testing/tests/moduletests/LCR/LCR_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_01.o: ../testing/tests/moduletests/SIG/SIG_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_02.o: ../testing/tests/moduletests/SIG/SIG_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_03.o: ../testing/tests/moduletests/SIG/SIG_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_01.o: ../testing/tests/moduletests/SYS/SYS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_02.o: ../testing/tests/moduletests/SYS/SYS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_03.o: ../testing/tests/moduletests/SYS/SYS_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_01.o: ../testing/tests/moduletests/TSW/TSW_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_02.o: ../testing/tests/moduletests/TSW/TSW_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_03.o: ../testing/tests/moduletests/TSW/TSW_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYST_01.o: ../testing/tests/systemtests/SYST_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYST_02.o: ../testing/tests/systemtests/SYST_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

else ifeq ($(config),qnd)
$(OBJDIR)/BAS_01.o: ../testing/tests/moduletests/BAS/BAS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/BAS_02.o: ../testing/tests/moduletests/BAS/BAS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_01.o: ../testing/tests/moduletests/LCR/LCR_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_02.o: ../testing/tests/moduletests/LCR/LCR_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_03.o: ../testing/tests/moduletests/LCR/LCR_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_01.o: ../testing/tests/moduletests/SIG/SIG_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_02.o: ../testing/tests/moduletests/SIG/SIG_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_03.o: ../testing/tests/moduletests/SIG/SIG_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_01.o: ../testing/tests/moduletests/SYS/SYS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_02.o: ../testing/tests/moduletests/SYS/SYS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_03.o: ../testing/tests/moduletests/SYS/SYS_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_01.o: ../testing/tests/moduletests/TSW/TSW_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_02.o: ../testing/tests/moduletests/TSW/TSW_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_03.o: ../testing/tests/moduletests/TSW/TSW_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYST_01.o: ../testing/tests/systemtests/SYST_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYST_02.o: ../testing/tests/systemtests/SYST_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

else ifeq ($(config),mod)
$(OBJDIR)/BAS_01.o: ../testing/tests/moduletests/BAS/BAS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/BAS_02.o: ../testing/tests/moduletests/BAS/BAS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_01.o: ../testing/tests/moduletests/LCR/LCR_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_02.o: ../testing/tests/moduletests/LCR/LCR_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_03.o: ../testing/tests/moduletests/LCR/LCR_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_01.o: ../testing/tests/moduletests/SIG/SIG_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_02.o: ../testing/tests/moduletests/SIG/SIG_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_03.o: ../testing/tests/moduletests/SIG/SIG_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_01.o: ../testing/tests/moduletests/SYS/SYS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_02.o: ../testing/tests/moduletests/SYS/SYS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_03.o: ../testing/tests/moduletests/SYS/SYS_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_01.o: ../testing/tests/moduletests/TSW/TSW_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_02.o: ../testing/tests/moduletests/TSW/TSW_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_03.o: ../testing/tests/moduletests/TSW/TSW_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

else ifeq ($(config),sys)
$(OBJDIR)/SYST_01.o: ../testing/tests/systemtests/SYST_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYST_02.o: ../testing/tests/systemtests/SYST_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

else ifeq ($(config),dev)
$(OBJDIR)/DT_01.o: ../testing/tests/devtests/DT_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/DT_02.o: ../testing/tests/devtests/DT_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/DT_03.o: ../testing/tests/devtests/DT_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

else ifeq ($(config),bullseye)
$(OBJDIR)/BAS_01.o: ../testing/tests/moduletests/BAS/BAS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/BAS_02.o: ../testing/tests/moduletests/BAS/BAS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_01.o: ../testing/tests/moduletests/LCR/LCR_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_02.o: ../testing/tests/moduletests/LCR/LCR_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LCR_03.o: ../testing/tests/moduletests/LCR/LCR_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_01.o: ../testing/tests/moduletests/SIG/SIG_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_02.o: ../testing/tests/moduletests/SIG/SIG_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SIG_03.o: ../testing/tests/moduletests/SIG/SIG_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_01.o: ../testing/tests/moduletests/SYS/SYS_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_02.o: ../testing/tests/moduletests/SYS/SYS_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/SYS_03.o: ../testing/tests/moduletests/SYS/SYS_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_01.o: ../testing/tests/moduletests/TSW/TSW_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_02.o: ../testing/tests/moduletests/TSW/TSW_02.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/TSW_03.o: ../testing/tests/moduletests/TSW/TSW_03.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

else ifeq ($(config),tmp)
$(OBJDIR)/TSW_01.o: ../testing/tests/moduletests/TSW/TSW_01.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

endif

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif