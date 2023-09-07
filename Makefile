#定义各文件路径
DIR_INC =./include
DIR_SRC =./src
DIR_OBJ =./obj
DIR_BIN =bin

#获取src路径下的所有c文件
SRC = $(wildcard $(DIR_SRC)/*.c)
#将src目录下的.c文件全部改成obj目录下的.o文件
OBJ = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir $(SRC)))

TARGET = $(DIR_BIN)/main

# .o文件生成的条件
$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c
	$CC -c  $^ -o $@  

#编译生成可执行文件
#$(TARGET) : $(OBJ)
#	gcc $^ -o $@

# 生成可执行文件
exec : $(OBJ)
	gcc $^ -o $@

# 执行文件
run : exec
	./$<

debug :
	@echo $(library_paths)

#清除文件命令
clean :
	rm -rf obj/*
	rm -rf bin/*

.PHONY:debug clean create run


