# creates release archives

all: release

release:
	rm -rf release/MatrixUtil

	mkdir -p release
	mkdir -p release/MatrixUtil
	mkdir -p release/MatrixUtil/include
	mkdir -p release/MatrixUtil/include/mutil
	cp MatrixUtil/*.h release/MatrixUtil/include/mutil
	cp MatrixUtil/matrixutil.natvis release/MatrixUtil/include/mutil

	(cd release/MatrixUtil && zip -r ../MatrixUtil.zip include)
	(cd release/MatrixUtil && tar -czf ../MatrixUtil.tar.gz include)

clean:
	rm -rf release