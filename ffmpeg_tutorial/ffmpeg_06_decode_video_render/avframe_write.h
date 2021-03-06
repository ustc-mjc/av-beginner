/*
* Copyright 2020 https://glumes.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     https://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef AV_BEGINNER_AVFRAME_WRITE_H
#define AV_BEGINNER_AVFRAME_WRITE_H

extern "C" {
#include <libavformat/avformat.h>
}

#include <iostream>

using namespace std;

static string pgm_path = string(PROJECT_DIR_PATH) + "/resource/gen/file-pgm";
static string yuv_path = string(PROJECT_DIR_PATH) + "/resource/gen/file-yuv";

static std::function<void(void *, int)> yuv_save = [](void *frame, int num) {
    AVFrame *avFrame = static_cast<AVFrame *>(frame);

    int size = avFrame->width * avFrame->height;

    char yuv_save_path[1024];
    sprintf(yuv_save_path,"%s-%dx%d.yuv",yuv_path.c_str(),avFrame->width,avFrame->height);

    FILE *f;
    f = fopen(yuv_save_path,num == 1 ? "wb" :"ab");

    fwrite(avFrame->data[0], 1, size, f);
    fwrite(avFrame->data[1], 1, size / 4, f);
    fwrite(avFrame->data[2], 1, size / 4, f);
    fclose(f);
    log("success write %d frame to yuv file",num);
};

static std::function<void(void *, int)> pgm_save = [](void *frame, int num) {
    AVFrame *avFrame = static_cast<AVFrame *>(frame);
    char single_frame_path[1024];
    sprintf(single_frame_path, "%s-%d.pgm", pgm_path.c_str(), num);

    FILE *f;
    f = fopen(single_frame_path, "wb+");
    fprintf(f, "P5\n%d %d\n%d\n", avFrame->width, avFrame->height, 255);

    for (int i = 0; i < avFrame->height; ++i) {
        fwrite(avFrame->data[0] + i * avFrame->linesize[0], 1, avFrame->width, f);
    }
    fclose(f);
    log("success write %d frame to pgm file",num);
};
#endif //AV_BEGINNER_AVFRAME_WRITE_H
