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

#ifndef AV_BEGINNER_TEXTURE_H
#define AV_BEGINNER_TEXTURE_H

#include <gl_base.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <log.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace std;

class Texture {

public:
    Texture(const string & fileName);

    ~Texture();

    void bind();

private:
    GLuint mTexture;
};


#endif //AV_BEGINNER_TEXTURE_H
