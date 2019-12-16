.PHONY: clean All

All:
	@echo "----------Building project:[ applyIterDistance - Debug ]----------"
	@cd "applyIterDistance" && "$(MAKE)" -f  "applyIterDistance.mk"
clean:
	@echo "----------Cleaning project:[ applyIterDistance - Debug ]----------"
	@cd "applyIterDistance" && "$(MAKE)" -f  "applyIterDistance.mk" clean
