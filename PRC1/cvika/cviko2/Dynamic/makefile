TARGET = make
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
CFLAGS +=-std=c++17 -pedantic -Wall
CFLAGS += -O2

	
bin: $(TARGET)
	@echo "Build was finished succesfully!"
	@echo "Running file $(TARGET):"
	@./$(TARGET)

$(OBJS):  %.o: %.cpp
	@clear
	@echo "Building..."
	@$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS) 
	@$(CXX) $(OBJS) $(LDFLAGS) -o $@

	@rm -rf $(OBJS)

# clean_obj:
# 	rm -rf $(OBJS)
clean:
	@clear
	@rm -rf $(OBJS) $(TARGET)
	@echo "Build was cleaned!"