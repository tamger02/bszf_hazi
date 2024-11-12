####################################################################
# Automatically-generated file. Do not edit!                       #
# Makefile Version 15                                              #
####################################################################

BASE_SDK_PATH = C:/Users/dbura/SimplicityStudio/SDKs/gecko_sdk
UNAME:=$(shell $(POSIX_TOOL_PATH)uname -s | $(POSIX_TOOL_PATH)sed -e 's/^\(CYGWIN\).*/\1/' | $(POSIX_TOOL_PATH)sed -e 's/^\(MINGW\).*/\1/')
ifeq ($(UNAME),MINGW)
# Translate "C:/super" into "/C/super" for MinGW make.
SDK_PATH := /$(shell $(POSIX_TOOL_PATH)echo $(BASE_SDK_PATH) | sed s/://)
endif
SDK_PATH ?= $(BASE_SDK_PATH)
COPIED_SDK_PATH ?= gecko_sdk_4.4.4

# This uses the explicit build rules below
PROJECT_SOURCE_FILES =

C_SOURCE_FILES   += $(filter %.c, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cpp, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cc, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.s, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.S, $(PROJECT_SOURCE_FILES))
LIB_FILES        += $(filter %.a, $(PROJECT_SOURCE_FILES))

C_DEFS += \

ASM_DEFS += \

INCLUDES += \

GROUP_START =-Wl,--start-group
GROUP_END =-Wl,--end-group

PROJECT_LIBS = \
 -lc \
 -lm

LIBS += $(GROUP_START) $(PROJECT_LIBS) $(GROUP_END)

LIB_FILES += $(filter %.a, $(PROJECT_LIBS))

C_FLAGS += \
 -std=c99 \
 -Wall \
 -Wextra \
 -Os \
 -g

CXX_FLAGS += \
 -std=c++11 \
 -Wall \
 -Wextra \
 -Os \
 -g

ASM_FLAGS += \
 -x assembler-with-cpp

LD_FLAGS += \
 -Xlinker -Map=$(OUTPUT_DIR)/$(PROJECTNAME).map \
 -Wl,--no-warn-rwx-segments


####################################################################
# Pre/Post Build Rules                                             #
####################################################################
pre-build:
	# No pre-build defined

post-build: $(OUTPUT_DIR)/$(PROJECTNAME).out
	# No post-build defined

####################################################################
# SDK Build Rules                                                  #
####################################################################
# Automatically-generated Simplicity Studio Metadata
# Please do not edit or delete these lines!
# SIMPLICITY_STUDIO_METADATA=eJztWo1v2jgU/1dQtJO2W5OUtXdbUdtpK0ziVA7Ex3qnZYqMY8BHYke209JO/d/v2fkAWugKXWGduk4hfn72+/nn5/j545vVajf/qp10/Xaz2bUq1jfPatdOP3Trn2v+bJZnVTzLs66tnaJEp9lrn9Q6UOjw/SQKS+dESMrZkWeVnV3PKhGGeUDZEAS97if7nWe9P/aExw5jwf8jWJXgNyZCXXYw/IJWJvcso1YqHQ54GBBRYijS2ShRfEhYka0VaEjybAcL7GPOBnSoXwFAIijItU7FPam4PQkA3aCfCOQ2GakKek7cKsdJRJiS7kd5Nfjtze4IXVG3D+/+jbfMvHvLjpvDdVO8eTLVAWsKWMlRVskAJSG0sRSiPgnnJH2ORHDCoxhK9GlI1eWR5rwUI6EWiBXnIR4hyhbkyWB8U4p55EgKVqUDuY5UCMMzgR6o7Dv6z7fL+2/3373Ze7v3bpbkgEgsaKxbcXzozqbyds+1NO1jN+tMkwKn6dQbrdP6Sb37r9/p9qr1pt9oVnunxn2+gNMJEvFzEoCbDVAoyY5n9RMaKspqExwmYBRyvnydijs8EXgqjXiQhMQ4ae5elUbDCEvgm0xWMumR53nWSKm44roXFxc5I0COK6XbSpUcgrkgWrOUmTPFlEhSIQ1MOsFOateRRCWxk+CT1C2cIcZGMQ6iuZLHHtBhOKMMmqWHi4TuVYqI1ITzu366mV7BYt6WY8+aUgCt1fVe7/wy9HVJFIdIkWcC1yIQKok5g49ZxySfSVyHRPhsRpxldbS4VB+hcPBM5lpkBuncBv4IJYbymcW1WHzazlgEbrcjp5+G4QTn5TdL7deFkVGr2iiias+7GVeDZGFkbexOo2tQy0LOu8MUXd/SQNwtqi09Hpr5WX/beBZNondiKuoGJfh/GNK+QOLyEyw7plbwLPa7FKMFijrQb5qIG1I6UQcvtqZS4NAJKRsTYZByI1yq48BQJBCqkwaKjW1d5hyFiTZvvH09BJo4qO47GHItB/uwAmEBrHjmAOCDgw3Zn0yWIHj9ulzeDIYLJJiZF1EYbqkbCghkogTaNoiYBIgpiudwmBln0x0iiE+E4EJuC4rWiOiVWVLPYZD06v4QIjQmegMEGhTpT9mM/9/EcYfqssFqSxUcrTJi77ARxysAiuPl4zcFtdIg/kEs5d7j3xzO9pmRbJ6kx0e0Fj+3vzX2WSbbIkePimoVnpYOfbspt8HQ4+BZHLEsUSuCFj9N+xGK56H8k9XnlWwIbI5evGz2uq1e16/W26/cFy+zTeu/PzRqrxxT+KE83kJOJb4VDc5UfUqlKqovYA8XAHGnSNbEiKQkUf+HgZxAoqjSvqBqZBsnegTkS7xiLdhn4Y5tM27rEW6Li4ktydDs9f8I5DPb6TSAxQPde5O6R6DAvxgakqBvFuu6hDNkiVP4ch9JcrOFD6gOU4GTEKZBEhMWwOrncv0w7udpFeMwj8MS6SEB2Brm4XO32AUfUtcT6aKprpMqOGEwCNFQPv2hN+2K+3CQaecs/CIcTCf1e/nB3EoEWNDfYIerEREhNHd1OhZsgXy3zCAiUkJb7JCwoRod7W7PfVYib1b/CdI3c3r72Nttdx23rLTtFkNZ020dReJjaMFcegstW3j2se3dzTWI3sge8Nz2+0r9nt65mNY9c0tk0WAZzO223jqRgKzi3CCblkGULz6C5XN1cfdjqaMt3upvN1u1drdu7kF801c3Kh78ep4l0TkB3+V4/BkJiiDyllpc0Q+toP/BdyemoBWMTzlOl2dZRiV/GRI85r4Mxr655JGLr9OHPpIo7p9s1rK+SZRWojehZXYNpGA6OyHZKXq+hdTIYFx6mgS6XNAhZSgslI00c1cQlHc0cqZgFobUwcEf5f3y7p/l66/W9f+oEiUH=END_SIMPLICITY_STUDIO_METADATA
# END OF METADATA