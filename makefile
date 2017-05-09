all:
	make -C nal
	make -C find

clean:
	make -C nal clean
	make -C find clean

.PHONY: all clean
