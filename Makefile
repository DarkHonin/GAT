LIBFT_DIR:=libft
LIBFT_GIT:=https://github.com/DarkHonin/LIBFT.git
TEST_DIR:=test

make:
	make -C $(LIBFT_DIR)
	gcc data_stream.c -L $(LIBFT_DIR) -lft -I $(LIBFT_DIR) -I .

test: $(TEST)
	

$(TEST_DIR):
	if [ ! -d "$(TEST_DIR)" ]; then	mkdir $(TEST_DIR); fi

$(TEST):
	gcc -o $(TEST_DIR)/$*.exe  *.c gat.h ".test/$(TEST)" -L $(LIBFT_DIR) -lft -I $(LIBFT_DIR) -I . 

setup:
	if [ ! -d "libft/.git" ]; then git clone $(LIBFT_GIT) $(LIBFT_DIR); \
	else \
	cd $(LIBFT_DIR) && pwd && git pull; \
	fi;