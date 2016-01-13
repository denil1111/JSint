SRC_DIR = src
FILES=`ls test/*.js`
define make_all_file
@for file in $(FILES); do \
( make ll $$file ) \
done;
endef

all: compiler
	 @$(make_all_file)
	 @./testFile

compiler:
	$(MAKE) -C $(SRC_DIR) -j
	@mv $(SRC_DIR)/JSint .

ll:
	@./Jsint -a < $(filter-out ll asm,$(MAKECMDGOALS)) > $(basename $(filter-out ll asm,$(MAKECMDGOALS))).res
	@node < $(filter-out ll asm,$(MAKECMDGOALS)) > $(basename $(filter-out ll asm,$(MAKECMDGOALS))).out

%:
	@:

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(RM) *.ll *.s

clean-all: clean
	$(RM) JSint
