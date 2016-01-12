SRC_DIR = src
FILES=`ls test/*.js`
define test_all_file
@for file in $(FILES); do \
( make ll $$file ) \
done;
endef
all: compiler
	 @$(test_all_file)

compiler:
	$(MAKE) -C $(SRC_DIR) -j
	@mv $(SRC_DIR)/JSint .

ll:
	@./Jsint debug < $(filter-out ll asm,$(MAKECMDGOALS)) > $(basename $(filter-out ll asm,$(MAKECMDGOALS))).res
	@echo "\033[1m" Test "\033[0m" $(filter-out ll asm,$(MAKECMDGOALS)) : "\c"
	@./compare $(basename $(filter-out ll asm,$(MAKECMDGOALS))).res $(basename $(filter-out ll asm,$(MAKECMDGOALS))).out
%:
	@:

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(RM) *.ll *.s

clean-all: clean
	$(RM) JSint
