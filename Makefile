.PHONY: clean All

All:
	@echo "----------Building project:[ IFS - Debug ]----------"
	@cd "IFS" && "$(MAKE)" -f  "IFS.mk"
	@echo "----------Building project:[ RandomPoints - Debug ]----------"
	@cd "5000AleatoriOrbits" && "$(MAKE)" -f  "RandomPoints.mk"
clean:
	@echo "----------Cleaning project:[ IFS - Debug ]----------"
	@cd "IFS" && "$(MAKE)" -f  "IFS.mk"  clean
	@echo "----------Cleaning project:[ RandomPoints - Debug ]----------"
	@cd "5000AleatoriOrbits" && "$(MAKE)" -f  "RandomPoints.mk" clean
