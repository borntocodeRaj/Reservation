include /usr/lib/oracle/11.2/client64/precomp/lib/env_precomp.mk

REVENUS_HDRS =  YmRevTarifs.h \
              YmRevTypePassager.h \
              YmRevDeviceType.h \
              YmRevClassMapping.h \
              YmRevDate.h \
              YmThreadBase.h \
              YmRevAnnulation.h \
              YmRevTcn.h \
              YmRevTpOD.h \
              YmRevTpFBC.h \
              YmRevRetraits.h \
              YmRevSegments.h \
              YmRevPassagersParcours.h \
              YmRevGlobal.h \
              YmRevTrNonYield.h
             

REVENUS_PHDRS =	YmRevMapTarifs.h \
              YmRevMapTypePassager.h \
              YmRevMapDeviceType.h \
              YmRevMapClassMapping.h \
              YmRevInfoBatch.h \
              YmRevMapTrLeg.h \
              YmRevMapTpOD.h \
              YmRevMapTpFBC.h \
              YmRevAnnuTpOD.h \
              YmRevTpNonTraite.h \
              YmRevTpFBCNonTraite.h \
              YmRevLireRetraits.h \
              YmRevMess.h \
              YmRevMapTrNonYield.h \
              YmRevEcrireVec.h \
              YmRevLireVec.h \
              YmRevLireAnnu.h          
                       

REVENUS_PROC = YmRevMapTarifs.pc \
     YmRevMapTypePassager.pc \
     YmRevMapDeviceType.pc \
     YmRevMapClassMapping.pc \
     YmRevInfoBatch.pc \
     YmRevMapTrLeg.pc \
     YmRevMapTpOD.pc \
     YmRevMapTpFBC.pc \
     YmRevAnnuTpOD.pc \
     YmRevTpNonTraite.pc \
     YmRevTpFBCNonTraite.pc \
     YmRevMess.pc \
     YmRevLireRetraits.pc \
     YmRevMain.pc \
     YmRevMapTrNonYield.pc \
     YmRevLireVec.pc \
     YmRevLireAnnu.pc\
     
     

REVENUS_SRCS = YmRevTarifs.cpp \
        YmRevTypePassager.cpp \
        YmRevDeviceType.cpp \
        YmRevClassMapping.cpp \
        YmThreadBase.cpp \
        YmRevAnnulation.cpp \
        YmRevTcn.cpp \
        YmRevTpOD.cpp \
        YmRevTpFBC.cpp \
        YmRevRetraits.cpp \
        YmRevSegments.cpp \
        YmRevPassagersParcours.cpp \
        YmRevDate.cpp \
        YmRevTrNonYield.cpp \
	YmRevEcrireVec.cpp
	
     	
REVENUS_OBJS=$(REVENUS_SRCS:.cpp=.o)

REVENUS_POBJS=$(REVENUS_PROC:.pc=.o)


revenus: $(REVENUS_OBJS) $(REVENUS_POBJS)
		$(CC)  -o ../../bin/revenus$(REVENUS_OBJS) $(REVENUS_POBJS) $(LDFLAGS) -L/usr/lib/oracle/11.2/client64/lib/ -lclntsh -o ./revenus$(PCCFLAGS)

.SUFFIXES: .pc .c .o .typ .h .cpp

.pc.o:
	proc $(PROCPPFLAGS) iname=$< 
	$(CPLUSPLUS) $(XCFLAGS) $(CFLAGS) $(CXXFLAGS) -L/usr/lib/oracle/11.2/client64/lib/ -lclntsh -c  $*.cpp -o $@

.cpp.o:
	$(CPLUSPLUS) $(XCFLAGS) $(CFLAGS) $(CXXFLAGS) -L/usr/lib/oracle/11.2/client64/lib/ -lclntsh -c  $*.cpp -o $@

.PHONY: all clean


#include $(ORACLE_HOME)/precomp/lib/env_precomp.mk
# description des dependances
#$(REVENUS_OBJS):$(REVENUS_HDRS) $(REVENUS_SRCS)

#$(REVENUS_POBJS):$(REVENUS_PHDRS) $(REVENUS_PROC)
$(REVENUS_OBJS):$(REVENUS_HDRS)

$(REVENUS_POBJS):$(REVENUS_PHDRS)


# These macro definitions fill in some details or override some defaults
INCLUDE=-I$(ORACLE_HOME) -I/usr/include/oracle/11.2/client64/ -I/usr/lib/oracle/11.2/client64/lib/precomp/public
CFLAGS=$(INCLUDE)
CPPFLAGS=SQLCA_STORAGE_CLASS=extern -D_REENTRANT
CXXFLAGS=-g -D POSIX_THREAD -D_REENTRANT $(INCLUDE)
CPLUSPLUS=g++ -lclntsh
CC=gcc
USERID=$(PROPRIO_BASE)
#OTTFLAGS=$(PCCFLAGS)
PRODUCT_LIBHOME=
MAKEFILE=./Makefile
PROCPLSFLAGS=userid=$(USERID) sqlcheck=full
#Support for all the ANSI 99 sql syntax (including joins) has been added in 11g with the new precompiler option common_parser
PROCPPFLAGS= code=cpp $(CPLUS_SYS_INCLUDE) $(PROCPLSFLAGS) parse=none cpp_suffix=cpp common_parser=yes
PLSQLHOME=$(ORACLE_HOME)/plsql/
I_SYM=-I
INCLUDE=-I -I/usr/lib/oracle/11.2/client64/precomp/public -I/usr/lib/oracle/11.2/client64/plsql/public  -I/home/apptymd/workspace/TGV/appl/src/revenus1
ORACLE_VN=11
ORACLE_LIB_DIR=$(ORACLE_HOME)/lib
ORACLE_LIB_OPTS=-lc -lclntsh -lm -ldl -lm -lpthread -lnsl # -lsql$(ORACLE_VN) -lclient$(ORACLE_VN) -lcommon$(ORACLE_VN) -lgeneric$(ORACLE_VN) -lcore$(ORACLE_VN) -lnls$(ORACLE_VN)
LINK_LIB_DIR_OPTS=-L$(RMAC_LIB_DIR) -L$(ORACLE_LIB_DIR) 
LINK_LIB_OPTS=$(ORACLE_LIB_OPTS)
LDFLAGS=$(LINK_LIB_DIR_OPTS) $(LINK_LIB_OPTS) -L/usr/lib/oracle/11.2/client64/lib/ -lclntsh -DSQLCA_STORAGE_CLASS=extern

all: 

clean: 
	@echo "Suppression des objets compilés"
	@rm $(REVENUS_OBJS) 2>/dev/null

cleanpc: 
	@echo "Suppression des objets pro-c"
	@rm $(REVENUS_POBJS) 2>/dev/null

re: clean cleanpc all

