/*******************************************************************
 * Copyright 2002-2021 Accusoft Corporation, Tampa Florida.        *
 * This sample code is provided to Accusoft licensees "as is"      *
 * with no restrictions on use or modification. No warranty for    *
 * use of this sample code is provided by Accusoft.                *
 *******************************************************************/

#include <linux/limits.h>
#include "barcodexpress.h"
#include "stdlib.h"
#include "stdio.h"

int main(const int argc, const char **argv) {

    const char* filename = "./test-barcodes.bmp";

    // The BX_AnalyzeParameters object will be passed to Barcode Xpress to tell
    // it what types of barcodes to scan for and to pass in other options.
    // By default, Barcode Xpress scans for all supported 1D Barcodes
    // with the exception of Patch Codes which can only be scanned for 
    // independently.
    BX_AnalyzeParameters params = BX_DefaultAnalyzeParameters;
    params.BarcodeTypes = 
        BX_BarcodeType_Code39 | 
        BX_BarcodeType_IntelligentMail |
        BX_BarcodeType_Code128 |
        BX_BarcodeType_DataMatrix |
        BX_BarcodeType_QRCode;

    BX_AnalyzeResult result;
    BX_Status status;
    status = BX_analyze_file( &params, filename, &result );

    if( 0 == result.BarcodeResultsLength ) {
        printf("No results\n");
        BX_free_analyze_result( &result );
        return 1;
    }

    for( int i=0; i<result.BarcodeResultsLength; ++i ) {
        BX_BarcodeResult *res = &result.BarcodeResults[i];
        printf("\tResult #%d\n", i+1);
        printf("\t\tBarcode Type: %s\n", res->Name);
        printf("\t\tValue: %s\n", res->Value);
        printf("\t\tConfidence: %ld\n\n", res->Confidence);
    }    

    BX_free_analyze_result( &result );

    return 0;
}
