LIBFT:="${CURDIR}/libft"
LIBTEST:="${CURDIR}/testing"
FLAGS:=-L$(LIBFT) -L$(LIBTEST) -lft -ltest -I$(LIBFT) -I$(LIBTEST) -I"${CURDIR}" 
TEST_DIR=tests
make:
	make -C $(LIBFT)
	make -C $(LIBTEST)
	gcc data_stream.c $(FLAGS)

re:
	make -C $(LIBFT) re
	make -C $(LIBTEST) re

$(TEST_DIR):
	if [ ! -d $(TEST_DIR) ]; then mkdir $(TEST_DIR); fi

test: $(TEST_DIR)
	make -C $(LIBTEST) test SRC="'${CURDIR}/$(SRC)' '${CURDIR}/data_stream.c'"\
		XFLAGS='$(FLAGS)' OUT='"${CURDIR}/$(TEST_DIR)"'

