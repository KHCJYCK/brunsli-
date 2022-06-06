// Copyright (c) Google LLC 2019
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

// Functions for reading a jpeg byte stream into a JPEGData object.
#define JPEG_HEADER

#ifndef BRUNSLI_ENC_JPEG_DATA_READER_H_
#define BRUNSLI_ENC_JPEG_DATA_READER_H_

#include <brunsli/jpeg_data.h>
#include <brunsli/types.h>

namespace brunsli {

enum JpegReadMode {
  JPEG_READ_HEADER,   // only basic headers
  JPEG_READ_TABLES,   // headers and tables (quant, Huffman, ...)
  JPEG_READ_ALL,      // everything
#ifdef JPEG_HEADER
  JPEG_READ_ORIGIN_HEAD, // decode部分读头文件
#endif
};

// Parses the JPEG stream contained in data[*pos ... len) and fills in *jpg with
// the parsed information.
// If mode is JPEG_READ_HEADER, it fills in only the image dimensions in *jpg.
// Returns false if the data is not valid JPEG, or if it contains an unsupported
// JPEG feature.
bool ReadJpeg(const uint8_t* data, const size_t len, JpegReadMode mode,
              JPEGData* jpg);
#ifdef JPEG_HEADER
bool ReadHeader(const uint8_t* data, const size_t len, JpegReadMode mode,
JPEGData* jpg, size_t& header_len);
#endif
}  // namespace brunsli
#endif  // BRUNSLI_ENC_JPEG_DATA_READER_H_
