#include <iostream>
#include <ctime>
#include <atlimage.h>
#include <Windows.h>

HBITMAP GetImageFromClipboard() {
    if (!OpenClipboard(NULL))
        return NULL;

    HBITMAP hBitmap = NULL;
    HANDLE hData = GetClipboardData(CF_BITMAP);
    if (hData != NULL)
        hBitmap = (HBITMAP)CopyImage((HBITMAP)hData, IMAGE_BITMAP, 0, 0, LR_COPYRETURNORG);

    CloseClipboard();
    return hBitmap;
}

int main() {
    HBITMAP hBitImage = GetImageFromClipboard();
    if (hBitImage != NULL) {

        std::time_t current_time;
        std::time(&current_time);
        std::tm timeinfo;
        localtime_s(&timeinfo, &current_time);
        char buffer[128];
        std::strftime(buffer, 128, "%Y-%m-%d-%H-%M-%S.png", &timeinfo);

        CImage image;
        image.Attach(hBitImage);
        image.Save(CA2W(buffer), Gdiplus::ImageFormatPNG);
        image.Detach();
        DeleteObject(hBitImage);
    }
    return 0;
}