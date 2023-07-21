
NAME	= webserv

CXXFLAGS	= -Wall -Wextra -Werror \
				-std=c++98 -MMD -MP
CPPFLAGS	= -I ./include

RM			= rm -rf

FILENAME	=	\
				main

SRCS_DIR	=	srcs
SRCS		=	$(addprefix $(SRCS_DIR)/, $(addsuffix .cpp, $(FILENAME)))

OBJS_DIR	=	objs
OBJS		=	$(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILENAME)))

DEPS			=	$(addprefix $(DEPS_DIR)/,$(addsuffix .d, $(FILENAME)))

.PHONY: all clean fclean re

all: $(NAME)

-include $(DEPS)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CXX) $(OBJS) $(OUTPUT_OPTION)
	@echo "\033[32mComplete✅"

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@$(COMPILE.cpp) $< $(OUTPUT_OPTION)

clean:
	@$(RM) $(OBJS_DIR)
	@echo "\033[31mClean🧽"

fclean:
	@$(RM) $(OBJS_DIR) $(NAME)
	@echo "\033[31mfclean🧼"

re:
	@make fclean
	@make all