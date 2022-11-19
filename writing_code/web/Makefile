CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -Wshadow -pedantic-errors

NAME			= server
NAME_DEBUG		:= $(NAME)_debug


CLASSES	= Server.cpp

# TMPLATES=

HEADERS	= $(patsubst %.cpp,%.hpp,$(CLASSES)) $(TMPLATES)
SRCS_FILES= \
			main.cpp \
			Server.cpp

SRCS	= $(patsubst %.cpp,$(TESTS_SRC_DIR)/%.cpp,$(SRCS_FILES)) $(CLASSES)
OBJDIR	= obj
OBJS	= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS_FILES))

all: $(NAME)

clean:
	$(RM) -rf $(OBJDIR)
	$(RM) -f $(NAME).dSYM

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

debug: clean
debug: CXXFLAGS := $(CXXFLAGS) -g -DDEBUG=1
debug: $(NAME_DEBUG)

test: $(NAME)
	./$^

$(NAME): $(OBJS) $(SRCS_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -I. -o $@

$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -I. -o $@

$(OBJDIR):
	mkdir $@


.PHONY: all clean fclean re
