//
// Created by Jinglei Yang on 4/25/17.
//

#ifndef RENDR_RENDERER_H
#define RENDR_RENDERER_H

namespace Rendr {
    class Renderer {
    public:
//        virtual Renderer(void){};
        virtual ~Renderer(){};
        virtual void init() = 0;
        virtual void render() = 0;
        virtual void resize(int w, int h) = 0;

    private:
    };
}
#endif //RENDR_RENDERER_H
