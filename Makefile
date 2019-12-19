.PHONY: clean All

All:
	@echo "----------Building project:[ IFS - Debug ]----------"
	@cd "IFS" && "$(MAKE)" -f  "IFS.mk"
	@echo "----------Building project:[ PuntsFixosIFS - Debug ]----------"
	@cd "PuntsFixosIFS" && "$(MAKE)" -f  "PuntsFixosIFS.mk"
clean:
	@echo "----------Cleaning project:[ IFS - Debug ]----------"
	@cd "IFS" && "$(MAKE)" -f  "IFS.mk"  clean
	@echo "----------Cleaning project:[ PuntsFixosIFS - Debug ]----------"
	@cd "PuntsFixosIFS" && "$(MAKE)" -f  "PuntsFixosIFS.mk" clean
