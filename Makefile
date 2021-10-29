TARGET		:= covid19Apocalypse
SOURCES		:= .
			
INCLUDES	:= include

LIBS = -lvita2d -lSceCommonDialog_stub -lSceGxm_stub -lSceDisplay_stub -lSceAppMgr_stub -lSceSysmodule_stub -lSceCtrl_stub -lmathneon -lSceAudio_stub -lvorbisenc -lvorbisfile -lvorbis -logg -lfreetype -lpng -ljpeg -lz -lc -lm


#CFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.c))
CFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/src/main.c))
CPPFILES   := $(foreach dir,$(SOURCES), $(wildcard $(dir)/*.cpp))
BINFILES := $(foreach dir,$(DATA), $(wildcard $(dir)/*.bin))
OBJS     := $(addsuffix .o,$(BINFILES)) $(CFILES:.c=.o) $(CPPFILES:.cpp=.o) 

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CXX      = $(PREFIX)-g++
CFLAGS  = -g -Wl,-q -O2
CXXFLAGS  = $(CFLAGS) -fno-exceptions -std=gnu++11 -fpermissive
ASFLAGS = $(CFLAGS)

all: $(TARGET).vpk

$(TARGET).vpk: eboot.bin
#	vita-mksfoex -s TITLE_ID=COVID19AP "$(TARGET)" param.sfo	
	vita-mksfoex -s TITLE_ID=COVID19AP "The End is Near" param.sfo	
	./pack_vpk.sh
	
eboot.bin: $(TARGET).velf
	vita-make-fself -s $< eboot.bin	
	
%.velf: %.elf
	vita-elf-create $< $@
	
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@
	
clean:
	@rm -rf *.velf *.elf *.vpk $(OBJS) param.sfo eboot.bin

# curl -T eboot.bin ftp://192.168.1.20:1337/ux0:/app/VITAGL005/
