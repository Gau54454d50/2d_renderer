#include <X11/Xlib.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // usleep

#define WIDTH  640
#define HEIGHT 480

int main() {
    Display* display = XOpenDisplay(NULL);
    if (!display) {
        return 1;
    }

    int screen = DefaultScreen(display);
    Window win = XCreateSimpleWindow(display, RootWindow(display, screen),
        10, 10, WIDTH, HEIGHT, 1, BlackPixel(display, screen), WhitePixel(display, screen));

    XSelectInput(display, win, ExposureMask | KeyPressMask);
    XMapWindow(display, win);

    XImage* img;
    char* framebuffer = calloc(WIDTH * HEIGHT * 4, 1); // 32-bit per pixel
    img = XCreateImage(display, DefaultVisual(display, screen), 24,
        ZPixmap, 0, framebuffer, WIDTH, HEIGHT, 32, 0);

    GC gc = XCreateGC(display, win, 0, NULL);

    int running = 1;
    while (running) {
        // Example: Animate a red square
        memset(framebuffer, 0, WIDTH * HEIGHT * 4);
        static int frame = 0;
        for (int y = 100; y < 120; y++) {
            for (int x = 100 + (frame % 200); x < 120 + (frame % 200); x++) {
                int offset = (y * WIDTH + x) * 4;
                framebuffer[offset + 2] = 255; // R
            }
        }

        XPutImage(display, win, gc, img, 0, 0, 0, 0, WIDTH, HEIGHT);
        usleep(16000); // ~60 FPS
        frame++;

        while (XPending(display)) {
            XEvent ev;
            XNextEvent(display, &ev);
            if (ev.type == KeyPress)
                running = 0;
        }
    }

    XDestroyImage(img);
    XDestroyWindow(display, win);
    XCloseDisplay(display);
    return 0;
}

