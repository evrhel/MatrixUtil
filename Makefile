# creates release archives

all: release

release:
	rm -rf release/MatrixUtil

	mkdir -p release
	mkdir -p release/MatrixUtil
	mkdir -p release/MatrixUtil/include
	cp MatrixUtil/*.h release/MatrixUtil/include
	cp MatrixUtil/matrixutil.natvis release/MatrixUtil/include

	zip -r release/MatrixUtil.zip release/MatrixUtil
	tar -czf release/MatrixUtil.tar.gz release/MatrixUtil

clean:
	rm -rf release