MAKECMD         = "%MATLAB%\bin\win32\gmake"
HOST            = PC
BUILD           = yes
SYS_TARGET_FILE = raptor.tlc
SHELL           = cmd

MODEL_NAME		= Lightning_McSeas_VCU_Copy
MODULES			= LIN2.c Timer_BGND_9AY_V.c Timer_ooqlV.c XCP_App.c can_753__0002.c can_754__0002.c data.c hw_user.c lin_1428__0007.c lin_general.c raptor_printf.c xcp_protocol.c XCP_App.c.c
NUMST           = 
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS =
NCSTATES =

$(MODEL_NAME).mot: 
	@echo ### Created Makefile ...

DO_NOT_USE_CHECKSUMS = 1

# EOF: raptor.tmf