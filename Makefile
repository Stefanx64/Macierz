.PHONY: clean All

All:
	@echo "----------Building project:[ Macierze - Debug ]----------"
	@$(MAKE) -f  "Macierze.mk"
clean:
	@echo "----------Cleaning project:[ Macierze - Debug ]----------"
	@$(MAKE) -f  "Macierze.mk" clean
