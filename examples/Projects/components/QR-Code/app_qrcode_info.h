/*
 * ESPRESSIF MIT License
 *
 * Copyright (c) 2019-2020 <ESPRESSIF SYSTEMS (SHANGHAI) PTE LTD>
 *
 * Permission is hereby granted for use on ESPRESSIF SYSTEMS chips only, in which case,
 * it is free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "quirc.h"
#include "esp_err.h"
#include "qifi_parser.h"

typedef struct {
    uint8_t name;
    uint32_t self_x;
    uint32_t self_y;
    uint32_t self_z;

    struct {
        char E_direction;
        uint8_t E_target_name;
        uint32_t E_distance;

        char S_direction;
        uint8_t S_target_name;
        uint32_t S_distance;

        char W_direction;
        uint8_t W_target_name;
        uint32_t W_distance;

        char N_direction;
        uint8_t N_target_name;
        uint32_t N_distance;
    } target_t;

} QR_Code_Info_t;

extern QR_Code_Info_t * info;

/**@fn		parse_elem(char * instr,char *search_str,int *buf_size)
 * @brief	截取instr字符串中第一个search_str子串之前的所有内容，并且instr向前移动
 * @param	instr [IN] - 原始字符串
 *			search_str [IN] - 参考字符串
 *			instr [OUT] - 移位之后的字符串
 *			search_str [IN] - 截取返回的字符串长度
 * @return	返回截取的字符串
**/
char *parse_elem(char * instr,char *search_str,int *buf_size);

/**
 * @brief   QR code info scan
*/
esp_err_t QR_code_info_scan(struct quirc *qr_recognizer);

#ifdef __cplusplus
}
#endif
