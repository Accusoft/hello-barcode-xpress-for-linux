# Hello Barcode Xpress for Linux

A minimal [Barcode Xpress](https://www.accusoft.com/products/barcode-xpress-collection/barcode-xpress/)
for Linux application which detects barcodes on a given bitmap image.

## Requirements

Compiling and running the sample will require the following dependencies:

* C++ Compiler
* CMake v2.6+

For a more detailed list, included supported operating systems and optional
dependencies for Barcode Xpress, see the official [Barcode Xpress For Linux Documentation](https://help.accusoft.com/BarcodeXpress/latest/BxLinuxCC/webframe.html#system-requirements.html)

## Running the Sample

Create a build directory:

```shell
mkdir build && cd build
```

Configure the project with CMake and compile:

```shell
cmake ..
make
```

Finally, run the sample:

```shell
./readbarcodes
```

This will run the sample and you should see output like this:

```text
  Result #1
    Barcode Type: IntelligentMail
    Value: 441231234561234567** UNLICENSED accusoft.com
    Confidence: 100

  Result #2
    Barcode Type: Code 39
    Value: CODE ** UNLICENSED accusoft.com
    Confidence: 100

  Result #3
    Barcode Type: Code 128
    Value: Code 1** UNLICENSED accusoft.com
    Confidence: 100

  Result #4
    Barcode Type: QR Code
    Value: Barcode Xpress - QR Co** UNLICENSED accusoft.com
    Confidence: 100

  Result #5
    Barcode Type: DataMatrix
    Value: Barcode Xpress - Data Matrix Writ** UNLICENSED accusoft.com
    Confidence: 100
```

_**NOTE:** Barcode Xpress runs in Watermark evaluation mode if started without
a license and the barcode value will be partially hidden. If you would like to
do a full-featured evaluation of the product, [contact us](mailto:info@accusoft.com)._
