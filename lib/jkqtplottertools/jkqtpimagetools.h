/*
    Copyright (c) 2008-2019 Jan W. Krieger (<jan@jkrieger.de>)

    

    This software is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License (LGPL) as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License (LGPL) for more details.

    You should have received a copy of the GNU Lesser General Public License (LGPL)
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef JKQTPIMAGETOOLS_H
#define JKQTPIMAGETOOLS_H
#include <QIcon>
#include <QDebug>
#include <QImage>
#include <QStringList>
#include "jkqtplottertools/jkqtp_imexport.h"
#include <cmath>
#include <cfloat>
#include <stdint.h>
#include <QColor>
#include "jkqtplottertools/jkqtptools.h"

#ifndef NO_JKQTPLOTTER
#include "jkqtplottertools/jkqtptools.h"

class JKQTPverticalIndependentAxis; // forward
class JKQTPhorizontalIndependentAxis; // forward
class JKQtBasePlotter; // forward
#endif

/*! \brief Width of the Palette-Icons, generated e.g. by JKQTPMathImageGetPaletteIcon()
    \ingroup jkqtptools_qt */
#define JKQTP_PALETTE_ICON_WIDTH 64
/*! \brief Height of the Palette-Icons, generated e.g. by JKQTPMathImageGetPaletteIcon()
    \ingroup jkqtptools_qt */
#define JKQTP_PALETTE_IMAGEICON_HEIGHT 64


/*! \brief available palettes for coloring an image
    \ingroup jkqtplotter_imagelots_tools
 */
enum JKQTPMathImageColorPalette {
    JKQTPMathImageGRAY=0, /*!< \image html palettes/palette_gray.png */
    JKQTPMathImageINVERTEDGRAY, /*!< \image html palettes/palette_invgray.png */
    JKQTPMathImageRED, /*!< \image html palettes/palette_red.png */
    JKQTPMathImageINVERTEDRED, /*!< \image html palettes/palette_invred.png */
    JKQTPMathImageGREEN, /*!< \image html palettes/palette_green.png */
    JKQTPMathImageINVERTEDGREEN, /*!< \image html palettes/palette_invgreen.png */
    JKQTPMathImageBLUE, /*!< \image html palettes/palette_blue.png */
    JKQTPMathImageINVERTEDBLUE, /*!< \image html palettes/palette_invblue.png */
    JKQTPMathImageCYAN, /*!< \image html palettes/palette_cyan.png */
    JKQTPMathImageINVERTED_CYAN, /*!< \image html palettes/palette_invcyan.png */
    JKQTPMathImageYELLOW, /*!< \image html palettes/palette_yellow.png */
    JKQTPMathImageINVERTED_YELLOW, /*!< \image html palettes/palette_invyellow.png */
    JKQTPMathImageMAGENTA, /*!< \image html palettes/palettes/palette_magenta.png */
    JKQTPMathImageINVERTED_MAGENTA, /*!< \image html palettes/palette_invmagenta.png */


    JKQTPMathImageMATLAB, /*!< \image html palettes/palette_Matlab.png */
    JKQTPMathImageINVERTED_MATLAB, /*!< \image html palettes/palette_invMatlab.png */
    JKQTPMathImageRYGB, /*!< \image html palettes/palette_RYGB.png */
    JKQTPMathImageINVERTED_RYGB, /*!< \image html palettes/palette_invRYGB.png */
    JKQTPMathImageHSV, /*!< \image html palettes/palette_HSV.png */
    JKQTPMathImageINVERTED_HSV, /*!< \image html palettes/palette_invHSV.png */
    JKQTPMathImageRAINBOW, /*!< \image html palettes/palette_rainbow.png */
    JKQTPMathImageINVERTED_RAINBOW, /*!< \image html palettes/palette_invrainbow.png */
    JKQTPMathImageHOT, /*!< \image html palettes/palette_AFMhot.png */
    JKQTPMathImageINVERTED_HOT, /*!< \image html palettes/palette_invAFMhot.png */
    JKQTPMathImageOCEAN, /*!< \image html palettes/palette_ocean.png */
    JKQTPMathImageINVERTED_OCEAN, /*!< \image html palettes/palette_invocean.png */
    JKQTPMathImageTRAFFICLIGHT, /*!< \image html palettes/palette_trafficlight.png */
    JKQTPMathImageINVERTED_TRAFFICLIGHT, /*!< \image html palettes/palette_invtrafficlight.png */
    JKQTPMathImageBLUEMAGENTAYELLOW, /*!< \image html palettes/palette_BlMaYe.png */
    JKQTPMathImageINVERTED_BLUEMAGENTAYELLOW, /*!< \image html palettes/palette_YeMaBl.png */
    JKQTPMathImageBLUEYELLOW, /*!< \image html palettes/palette_BlYe.png */
    JKQTPMathImageINVERTED_BLUEYELLOW, /*!< \image html palettes/palette_YeBl.png */

    JKQTPMathImageBLUEWHITERED, /*!< \image html palettes/palette_bluewhitered.png */
    JKQTPMathImageREDWHITEBLUE, /*!< \image html palettes/palette_redwhiteblue.png */

    JKQTPMathImageBLACKBLUEREDYELLOW, /*!< \image html palettes/palette_BBlRdYe.png */
    JKQTPMathImageGREENREDVIOLET, /*!< \image html palettes/palette_GnRdVi.png */
    JKQTPMathImageBLACKBLUEVIOLETYELLOWWHITE,
    JKQTPMathImageWHITEYELLOWVIOLETBLUEBLACK, /*!< \image html palettes/palette_.png */
    JKQTPMathImageBR_GR, /*!< \image html palettes/palette_BrBG.png */
    JKQTPMathImagePU_OR, /*!< \image html palettes/palette_PuOr.png */
    JKQTPMathImageGN_BU, /*!< \image html palettes/palette_greenblue.png */
    JKQTPMathImageBU_GN, /*!< \image html palettes/palette_bluegreen.png */
    JKQTPMathImageYL_GN_BU, /*!< \image html palettes/palette_YeGnBu.png */

    JKQTPMathImageBR_GR_STEP, /*!< \image html palettes/palette_stepsBrBG.png */
    JKQTPMathImagePU_OR_STEP, /*!< \image html palettes/palette_stepsPuOr.png */
    JKQTPMathImageGN_BU_STEP, /*!< \image html palettes/palette_stepsGnBl.png */
    JKQTPMathImageBU_GN_STEP, /*!< \image html palettes/palette_stepsBlGn.png */
    JKQTPMathImageYL_GN_BU_STEP, /*!< \image html palettes/palette_stepsYeGnBu.png */


    JKQTPMathImageCYANWHITE, /*!< \image html palettes/palette_cyanwhite.png */
    JKQTPMathImageINVERTED_CYANWHITE, /*!< \image html palettes/palette_whitecyan.png */
    JKQTPMathImageYELLOWWHITE, /*!< \image html palettes/palette_yellowwhite.png */
    JKQTPMathImageINVERTED_YELLOWWHITE, /*!< \image html palettes/palette_whiteyellow.png */
    JKQTPMathImageMAGENTAWHITE, /*!< \image html palettes/palette_magentawhite.png */
    JKQTPMathImageINVERTED_MAGENTAWHITE, /*!< \image html palettes/palette_whitemagenta.png */
    JKQTPMathImageBlueGreenRed, /*!< \image html palettes/palette_bluegreenred.png */
    JKQTPMathImageRedGreenBlue, /*!< \image html palettes/palette_redgreenblue.png */

    JKQTPMathImagePREDEFINED_PALETTES_COUNT,

    JKQTPMathImageUSER_PALETTE=65000,

    JKQTPMathImageALPHA=JKQTPMathImageUSER_PALETTE-2,
    JKQTPMathImageINVERTED_ALPHA=JKQTPMathImageUSER_PALETTE-1
};









/*! \brief modes available for image pixels that are above/below the pixel value range
    \ingroup jkqtplotter_imagelots_tools
 */
enum JKQTPMathImageColorRangeFailAction {
    JKQTPMathImageLastPaletteColor=0, /*!< set to last color in the palette */
    JKQTPMathImageGivenColor=1, /*!< set to the provided min/max color */
    JKQTPMathImageTransparent=2 /*!< set transparent */
};


/*! \brief modes available for RGB images
    \ingroup jkqtplotter_imagelots_tools
 */
enum JKQTPRGBMathImageRGBMode {
    JKQTPRGBMathImageModeRGBMode=0,
    JKQTPRGBMathImageModeHSVMode=1,
    JKQTPRGBMathImageModeHSLMode=2,
    JKQTPRGBMathImageModeCMYMode=3
};


/*! \brief returns a vector containing all elements of the given array
    \ingroup jkqtplotter_imagelots_tools

*/
template <class T>
inline QVector<T> JKQTPimagePlot_arrayToVector(const T* input, int N) {
    if (!input || N<=0) return QVector<double>();
    T dummy;
    QVector<T> out(N, dummy);
    memcpy(out.data(), input, N*sizeof(T));
    return out;
}

/*! \brief returns a vector containing all elements of the given array as doubles
    \ingroup jkqtplotter_imagelots_tools

*/
template <class T>
inline QVector<double> JKQTPimagePlot_arrayToDVector(const T* input, int N) {
    if (!input || N<=0) return QVector<double>();
    QVector<double> out(N, 0.0);
    for (int i=0; i<N; i++) {
        out[i]=input[i];
    }
    return out;
}

/*! \brief returns a vector containing all elements of the given boolean array as doubles (true=1, false=0)
    \ingroup jkqtplotter_imagelots_tools

*/
inline QVector<double> JKQTPimagePlot_BarrayToDVector(const bool* input, int N) {
    if (!input || N<=0) return QVector<double>();
    QVector<double> out(N, 0.0);
    for (int i=0; i<N; i++) {
        if (input[i]) out[i]=1.0;
    }
    return out;
}

/*! \brief fin the minimum pixel value in the given image \a dbl with width \a width and height \a height
    \ingroup jkqtplotter_imagelots_tools

 */
template <class T>
inline double JKQTPimagePlot_getImageMin(T* dbl, int width, int height)
{
    if (!dbl || width<=0 || height<=0)
            return 0;

    double min = 0;
    double max = 0;
    bool first=true;
    for (int i=1; i<width*height; ++i)
    {
        T v=dbl[i];
        if (!(std::isnan(static_cast<long double>(v)) || std::isinf(static_cast<long double>(v)))) {
            if (first) {
                min=max=v;
                first=false;
            } else {
                if (v < min)
                    min = v;
                else if (v > max)
                    max = v;
            }
        }
    }
    return min;
};

/*! \brief fin the maximum pixel value in the given image \a dbl with width \a width and height \a height
    \ingroup jkqtplotter_imagelots_tools

 */
template <class T>
inline double JKQTPimagePlot_getImageMax(T* dbl, int width, int height)
{
    if (!dbl || width<=0 || height<=0)
            return 0;

    double min = 0;
    double max = 0;
    bool first=true;
    for (int i=1; i<width*height; ++i)
    {
        T v=dbl[i];
        if (!(std::isnan(static_cast<long double>(v)) || std::isinf(static_cast<long double>(v)))) {
            if (first) {
                min=max=v;
                first=false;
            } else {
                if (v < min)
                    min = v;
                else if (v > max)
                    max = v;
            }
        }
    }
    return max;
};









/*! \brief convert a 2D image (as 1D array) into a QImage and puts the image values into one color channel (set by \a channel).The other color channels are not changed! So a repeated call to this function for the SAME QImage will
           result in a step-by-step buildup of an image.
    \ingroup jkqtplotter_imagelots_tools

    \note  All calls (except channel>=3, i.e. alpha) set alpha to 255. Only the call
           with channel==3 (alpha) sets alpha to the desired value. Calls with channel==4 (saturation), channel==5 (value)
           leave alpha as it is.
*/
template <class T>
inline void JKQTPimagePlot_array2RGBimage(T* dbl_in, int width, int height, QImage &img, int channel, T minColor, T maxColor, JKQTPRGBMathImageRGBMode rgbMode=JKQTPRGBMathImageModeRGBMode, bool logScale=false, double logBase=10.0)
{
    if (!dbl_in || width<=0 || height<=0)
        return;

    double min = *dbl_in;
    double max = *dbl_in;
    bool first=true;
    if (minColor == maxColor) {
        for (int i=1; i<width*height; ++i)
        {
            T v=dbl_in[i];
            if (std::isfinite(static_cast<long double>(v))) {
                if (first) {
                    min=max=v;
                    first=false;
                } else {
                    if (v < min)
                        min = v;
                    else if (v > max)
                        max = v;
                }
            }
        }
    } else {
        min = minColor;
        max = maxColor;
    }


    T* dbl=dbl_in;
    if (logScale) {
        double logB=log10(logBase);
        dbl=(T*)malloc(width*height*sizeof(T));
        //memcpy(dbl, dbl_in, width*height*sizeof(T));
        for (int i=0; i<width*height; i++) {
            dbl[i]=log10(dbl_in[i])/logB;
        }
        min=log10(min)/logB;
        max=log10(max)/logB;
    }
    double delta=max-min;

    if (min != max) {
        if (rgbMode==JKQTPRGBMathImageModeRGBMode) {
            //qDebug()<<"RGBMode";
            if (channel==0) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = trunc(double(dbl[j*width+i]-min)*255.0/delta);
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        const QRgb l=line[i];
                        //if (j==5) qDebug()<<"r: "<<v<<qGreen(l)<<qBlue(l)<<qAlpha(255);
                        line[i]=qRgb(v,qGreen(l),qBlue(l));
                    }
                }
            } else if (channel==1) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        const QRgb l=line[i];
                        //if (j==5) qDebug()<<"g: "<<qRed(l)<<v<<qBlue(l)<<qAlpha(255);
                        line[i]=qRgb(qRed(l),v,qBlue(l));
                    }
                }
            } else if (channel==2) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        const QRgb l=line[i];
                        //if (j==5) qDebug()<<"b: "<<qRed(l)<<qGreen(l)<<v<<qAlpha(255);
                        line[i]=qRgb(qRed(l),qGreen(l),v);
                    }
                }
            }
        } else if (rgbMode==JKQTPRGBMathImageModeCMYMode) {
            //qDebug()<<"RGBMode";
            if (channel==0) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = trunc(double(dbl[j*width+i]-min)*255.0/delta);
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        const QRgb l=line[i];
                        //if (j==5) qDebug()<<"r: "<<v<<qGreen(l)<<qBlue(l)<<qAlpha(255);
                        line[i]=QColor::fromCmyk(v,QColor(l).magenta(),QColor(l).yellow(),QColor(l).black()).rgba();
                    }
                }
            } else if (channel==1) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        const QRgb l=line[i];
                        //if (j==5) qDebug()<<"g: "<<qRed(l)<<v<<qBlue(l)<<qAlpha(255);
                        line[i]=QColor::fromCmyk(QColor(l).cyan(),v,QColor(l).yellow(),QColor(l).black()).rgba();
                    }
                }
            } else if (channel==2) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        const QRgb l=line[i];
                        //if (j==5) qDebug()<<"b: "<<qRed(l)<<qGreen(l)<<v<<qAlpha(255);
                        line[i]=QColor::fromCmyk(QColor(l).cyan(),QColor(l).magenta(),v,QColor(l).black()).rgba();
                    }
                }
            }
        } else if (rgbMode==JKQTPRGBMathImageModeHSVMode) {
            if (channel==0) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = trunc(double(dbl[j*width+i]-min)*220.0/delta);
                        v = (v < 0) ? 0 : ( (v > 360) ? 360 : v);
                        QColor l=QColor::fromRgb(line[i]);
                        //if (i<10 && j==5) qDebug()<<"hi: "<<l.name()<<dbl[j*width+i]<<min<<max;
                        l.setHsv(v, l.saturation(), l.value());
                        //if (i<10 && j==5) qDebug()<<"ho: "<<l.name();
                        line[i]=l.rgb();
                    }
                }
            } else if (channel==1) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        QColor l=QColor::fromRgb(line[i]);
                        //if (i<10 && j==5) qDebug()<<"si: "<<l.name()<<dbl[j*width+i]<<min<<max;
                        l.setHsv(l.hue(), v, l.value());
                        //if (i<10 && j==5) qDebug()<<"so: "<<l.name();
                        line[i]=l.rgb();
                    }
                }
            } else if (channel==2) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        QColor l=QColor::fromRgb(line[i]);
                        //if (i<10 && j==5) qDebug()<<"vi: "<<l.name()<<dbl[j*width+i]<<min<<max;
                        l.setHsv(l.hue(), l.saturation(), v);
                        //if (i<10 && j==5) qDebug()<<"vo: "<<l.name();
                        line[i]=l.rgb();
                    }
                }

            }
        } else if (rgbMode==JKQTPRGBMathImageModeHSLMode) {
            if (channel==0) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = trunc(double(dbl[j*width+i]-min)*255.0/delta);
                        v = (v < 0) ? 0 : ( (v > 360) ? 360 : v);
                        QColor l=line[i];
                        l.setHsl(v, l.saturation(), l.lightness());
                        line[i]=l.rgb();
                    }
                }
            } else if (channel==1) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        QColor l=line[i];
                        l.setHsl(l.hue(), v, l.lightness());
                        line[i]=l.rgb();
                    }
                }
            } else if (channel==2) {
                for (int j=0; j<height; ++j) {
                    QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                    for (int i=0; i<width; ++i) {
                        int v = (dbl[j*width+i]-min)*255/delta;
                        v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                        QColor l=line[i];
                        l.setHsl(l.hue(), l.saturation(), v);
                        line[i]=l.rgb();
                    }
                }

            }
        }
        if (channel==3) {
           for (int j=0; j<height; ++j) {
               QRgb* line=(QRgb*)(img.scanLine(height-1-j));
               for (int i=0; i<width; ++i) {
                   int v = (dbl[j*width+i]-min)*255/delta;
                   v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                   const QRgb l=line[i];
                   line[i]=qRgba(qRed(l),qGreen(l),qBlue(l),v);
               }
           }
        } else if (channel==4) {
            for (int j=0; j<height; ++j) {
                QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                for (int i=0; i<width; ++i) {
                    int v = (dbl[j*width+i]-min)*255/delta;
                    v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                    QColor c=QColor::fromRgba(line[i]);
                    c.setHsv(c.hue(), v, c.value(), c.alpha());
                    line[i]=c.rgba();
                }
            }
        } else if (channel==5) {
            for (int j=0; j<height; ++j) {
                QRgb* line=(QRgb*)(img.scanLine(height-1-j));
                for (int i=0; i<width; ++i) {
                    int v = (dbl[j*width+i]-min)*255/delta;
                    v = (v < 0) ? 0 : ( (v > 255) ? 255 : v);
                    QColor c=QColor::fromRgba(line[i]);
                    c.setHsv(c.hue(), c.saturation(), v, c.alpha());
                    line[i]=c.rgba();
                }
            }
       }
     }

    if (logScale) free(dbl);
}


/*! \brief Generate a QList with \a N entries of the value \a defaultValue
    \ingroup jkqtptools_qt */
template <typename T>
inline QList<T> JKQTPimagePlot_makeQList(const T& defaultVal, int N=1) {
    QList<T> l;
    for (int i=0; i<N; i++) l<<defaultVal;
    return l;
}



/*! \brief size of the lookup tables used by JKQTFPimagePlot_array2image()
    \ingroup jkqtplotter_imagelots_tools
*/
#define JKQTPimagePlot_LUTSIZE 256

/*! \brief build a linearly interpolated palette in \a lut with \a N entries that are provided in \a items
    \ingroup jkqtplotter_imagelots_tools

    The entries in \a items are sorted by the first (double) argument and the full range is distributed
    over 0 ... lut_size. Values in the LUT in between are generated by linear interpolations

    \a lut needs to have \c lut_size) entries
*/
void LIB_EXPORT JKQTPimagePlot_buildDefinedPaletteLinInterpolate(int* lut, QList<QPair<double, QRgb> > items, int lut_size=JKQTPimagePlot_LUTSIZE);

/*! \brief build a linearly interpolated palette in \a lut with \a N entries that are provided as (double, QRgb) value pairss in the variable arguments
    \ingroup jkqtplotter_imagelots_tools

    The entries in \a items are sorted by the first (double) argument and the full range is distributed
    over 0 ... lut_size. Values in the LUT in between are generated by linear interpolations

    \a lut needs to have \c lut_size) entries
*/
void LIB_EXPORT JKQTPimagePlot_buildDefinedPaletteLinInterpolate(int* lut, int N, ...);

/*! \brief build a palette in \a lut with \a N entries that are provided in \a items
    \ingroup jkqtplotter_imagelots_tools

    The entries in \a items are sorted by the first (double) argument and the full range is distributed
    over 0 ... JKQTPimagePlot_LUTSIZE.

    \a lut needs to have \c JKQTPimagePlot_LUTSIZE) entries
*/
void LIB_EXPORT JKQTPimagePlot_buildDefinedPalette(int* lut, QList<QPair<double, QRgb> > items);

/*! \brief build a palette in \a lut with \a N entries that are provided as as (double, QRgb) value pairss in the variable arguments
    \ingroup jkqtplotter_imagelots_tools
*/
void LIB_EXPORT JKQTPimagePlot_buildDefinedPalette(int* lut, int N, ...);

/*! \brief return a list of all globally available LUTs
    \ingroup jkqtplotter_imagelots_tools */
QStringList LIB_EXPORT JKQTPimagePlot_getPredefinedPalettes();



/*! \brief create a LUT for a given JKQTPMathImageColorPalette, store it in \a lutstore and return it
    \ingroup jkqtplotter_imagelots_tools
	\internal
	*/
LIB_EXPORT int* JKQTPimagePlot_getCreateLUT(QList<int *> &lutstore, JKQTPMathImageColorPalette palette);
/*! \brief frees a list of LUTs
    \ingroup jkqtplotter_imagelots_tools
	\internal
	*/
void LIB_EXPORT JKQTPimagePlot_freeLUTs(QList<int *> &lutstore);


/*! \brief internal global storage object for lookup-tables
    \ingroup jkqtplotter_imagelots_tools
	\internal
	*/
extern LIB_EXPORT QList<int*> global_jkqtpimagetools_lutstore;

/*! \brief convert a 2D image (as 1D array) into a QImage with given palette (see JKQTFPColorPalette)
    \ingroup jkqtplotter_imagelots_tools

    This method uses lookup tables which are saved as static variables to convert the 2D array into
    an image. The luts are only created once, and stored then, so mor CPU time is saved. The precompiler define
    JKQTPimagePlot_LUTSIZE sets the size of the LUTs. Note that if you don't use a specific color palette,
    the according LUT won't be calculated and stored!

    \param dbl_in pointer to a 1D array of template type \c T representing the image to plot. This array has to be of size \a width * \a height
    \param width width of the array in \a dbl
    \param height height of the array in \a dbl
    \param[out] im the QImage object to draw to (should be initialized as \c QImage::Format_ARGB32 )
    \param palette the color palette to use for the display
    \param minColor lower boundary of color range in \a dbl pixels, if \a minColor == \a maxColor then this function will extract the image min and image max.
    \param maxColor upper boundary of color range in \a dbl pixels, if \a minColor == \a maxColor then this function will extract the image min and image max.
    \param paletteMinFail specifies what shell happen, when a value in \a dbl is below \a minColor
    \param paletteMaxFail specifies what shell happen, when a value in \a dbl is above \a maxColor
    \param minFailColor color to use for pixels that are below \a minColor for some settings of \a paletteMinFail
    \param maxFailColor color to use for pixels that are below \a maxColor for some settings of \a paletteMaxFail
    \param nanColor color to use for pixels that are not-a-number
    \param infColor color to use for pixels that are infinity
*/
template <class T>
inline void JKQTPimagePlot_array2image(const T* dbl_in, int width, int height, QImage &img, JKQTPMathImageColorPalette palette, T minColor, T maxColor, JKQTPMathImageColorRangeFailAction paletteMinFail=JKQTPMathImageLastPaletteColor, JKQTPMathImageColorRangeFailAction paletteMaxFail=JKQTPMathImageLastPaletteColor, QColor minFailColor=QColor("black"), QColor maxFailColor=QColor("black"), QColor nanColor=QColor("black"), QColor infColor=QColor("black"), bool logScale=false, double logBase=10.0, const int* lutUser=0, int lutUserSize=0)
{    
    if (!dbl_in || width<=0 || height<=0)
            return;

    double min = *dbl_in;
    double max = *dbl_in;
    if (minColor == maxColor) {
        bool first=true;
        for (int i=1; i<width*height; ++i)
        {
            T v=dbl_in[i];
            if (!(std::isnan(static_cast<long double>(v)) || std::isinf(static_cast<long double>(v)))) {
                if (first) {
                    min=max=v;
                    first=false;
                } else {
                    if (v < min)
                        min = v;
                    else if (v > max)
                        max = v;
                }
            }
        }

    } else {
        min = minColor;
        max = maxColor;
    }

    const T* dbl=dbl_in;
    T* dbl1=nullptr;
    if (logScale) {
        double logB=log10(logBase);
        dbl1=(T*)malloc(width*height*sizeof(T));
        //memcpy(dbl, dbl_in, width*height*sizeof(T));
        for (int i=0; i<width*height; i++) {
            dbl1[i]=log10(dbl_in[i])/logB;
        }
        dbl=dbl1;
        min=log10(min)/logB;
        max=log10(max)/logB;
    }
    double delta=max-min;


    const int* lut_used=nullptr;
    int lutSize=JKQTPimagePlot_LUTSIZE;
    if (global_jkqtpimagetools_lutstore.size()<=0) global_jkqtpimagetools_lutstore=JKQTPimagePlot_makeQList<int*>(nullptr, JKQTPimagePlot_getPredefinedPalettes().size()+2);


    img = QImage(width, height, QImage::Format_ARGB32);
    if (min == max)
            img.fill(0);
    else
    {

        if (palette==JKQTPMathImageUSER_PALETTE) {
            lut_used=lutUser;
            lutSize=lutUserSize;
            //qDebug()<<"user palette "<<lutUser<<lutUserSize;
        } else {
            lut_used=JKQTPimagePlot_getCreateLUT(global_jkqtpimagetools_lutstore, palette);
        }


        if (lut_used!=nullptr && lutSize>0) {
            const unsigned int* lut_usedui=reinterpret_cast<const unsigned int*>(lut_used);
            // LUT found: collor the image accordingly
            for (int j=0; j<height; ++j) {
                QRgb* line=reinterpret_cast<QRgb*>(img.scanLine(height-1-j));
                for (int i=0; i<width; ++i) {
                    double val=dbl[j*width+i];
                    if (std::isnan(val)) {
                        line[i]=nanColor.rgba();
                    } else if (std::isinf(val)) {
                        line[i]=infColor.rgba();
                    } else {
                        const int v = static_cast<int>((val-min)/delta*static_cast<double>(lutSize));
                        const int vv = (v < 0) ? 0 : ( (v > lutSize) ? (lutSize) : v);
                        line[i]=lut_usedui[vv];
                        if ((v<0)&&(paletteMinFail==JKQTPMathImageGivenColor)) {
                            line[i]=minFailColor.rgba();
                        } else if ((v>lutSize)&&(paletteMaxFail==JKQTPMathImageGivenColor)) {
                            line[i]=maxFailColor.rgba();
                        } else if ((v<0)&&(paletteMinFail==JKQTPMathImageTransparent)) {
                            line[i]=QColor(Qt::transparent).rgba();
                        } else if ((v>lutSize)&&(paletteMaxFail==JKQTPMathImageTransparent)) {
                            line[i]=QColor(Qt::transparent).rgba();
                        }
                    }
                }
            }
        } else {
            // no LUT found: paint a black image!
            img.fill(0);
        }
    }

    if (dbl1) free(dbl1);

};

/*! \brief convert a 2D image (as 1D array) into a QImage with given palette (see JKQTFPColorPalette)
    \ingroup jkqtplotter_imagelots_tools

    This method uses lookup tables which are saved as static variables to convert the 2D array into
    an image. The luts are only created once, and stored then, so mor CPU time is saved. The precompiler define
    JKQTPimagePlot_LUTSIZE sets the size of the LUTs. Note that if you don't use a specific color palette,
    the according LUT won't be calculated and stored!

    \param dbl_in pointer to a 1D array of template type \c T representing the image to plot. This array has to be of size \a width * \a height
    \param width width of the array in \a dbl
    \param height height of the array in \a dbl
    \param[out] im the QImage object to draw to (should be initialized as \c QImage::Format_ARGB32 )
    \param lutUser user-defined lookup-table
	\param lutUserSize number of entries in \a lutUser
    \param minColor lower boundary of color range in \a dbl pixels, if \a minColor == \a maxColor then this function will extract the image min and image max.
    \param maxColor upper boundary of color range in \a dbl pixels, if \a minColor == \a maxColor then this function will extract the image min and image max.
    \param paletteMinFail specifies what shell happen, when a value in \a dbl is below \a minColor
    \param paletteMaxFail specifies what shell happen, when a value in \a dbl is above \a maxColor
    \param minFailColor color to use for pixels that are below \a minColor for some settings of \a paletteMinFail
    \param maxFailColor color to use for pixels that are below \a maxColor for some settings of \a paletteMaxFail
    \param nanColor color to use for pixels that are not-a-number
    \param infColor color to use for pixels that are infinity
*/
template <class T>
inline void JKQTPimagePlot_array2image(const T* dbl_in, int width, int height, QImage &img, const int* lutUser, int lutUserSize, T minColor, T maxColor, JKQTPMathImageColorRangeFailAction paletteMinFail=JKQTPMathImageLastPaletteColor, JKQTPMathImageColorRangeFailAction paletteMaxFail=JKQTPMathImageLastPaletteColor, QColor minFailColor=QColor("black"), QColor maxFailColor=QColor("black"), QColor nanColor=QColor("black"), QColor infColor=QColor("black"), bool logScale=false, double logBase=10.0)
{
    JKQTPimagePlot_array2image(dbl_in,  width,  height, img,  JKQTPMathImageUSER_PALETTE, minColor, maxColor,  paletteMinFail,  paletteMaxFail,  minFailColor,  maxFailColor,  nanColor,  infColor,  logScale,  logBase, lutUser, lutUserSize);
}





/*! \brief generates a QImage with width \a width and height 1 for the i-th color palette (\a i is based on the list returned by JKQTPimagePlot_getPredefinedPalettes() )
    \ingroup jkqtplotter_imagelots_tools */
QImage LIB_EXPORT JKQTPMathImageGetPaletteImage(int i, int width);
/*! \brief generates a QImage with width \a width and height \a height for the i-th color palette (\a i is based on the list returned by JKQTPimagePlot_getPredefinedPalettes() )
    \ingroup jkqtplotter_imagelots_tools */
QImage LIB_EXPORT JKQTPMathImageGetPaletteImage(int i, int width, int height);
/*! \brief generates a QImage with width \a width and height 1 for a specific JKQTPMathImageColorPalette
    \ingroup jkqtplotter_imagelots_tools */
QImage LIB_EXPORT JKQTPMathImageGetPaletteImage(JKQTPMathImageColorPalette palette, int width);
/*! \brief generates a QImage with width \a width and height \a height for a specific JKQTPMathImageColorPalette
    \ingroup jkqtplotter_imagelots_tools */
QImage LIB_EXPORT JKQTPMathImageGetPaletteImage(JKQTPMathImageColorPalette palette, int width, int height);
/*! \brief generates a QImage with width \a width and height 1 for a lookup-table \a lut with \a lut_size entries
    \ingroup jkqtplotter_imagelots_tools */
QImage LIB_EXPORT JKQTPMathImageGetPaletteImage(int* lut, int lut_size, int width);
/*! \brief generates a QImage with width \a width and height \a height for a lookup-table \a lut with \a lut_size entries
    \ingroup jkqtplotter_imagelots_tools */
QImage LIB_EXPORT JKQTPMathImageGetAlphaPaletteImage(int* lut, int lut_size, int width, int height);

/*! \brief generates a QIcon for the i-th color palette (\a i is based on the list returned by JKQTPimagePlot_getPredefinedPalettes() )
    \ingroup jkqtplotter_imagelots_tools */
QIcon LIB_EXPORT JKQTPMathImageGetPaletteIcon(int i) ;


/*! \brief generates a QIcon for a specific JKQTPMathImageColorPalette
    \ingroup jkqtplotter_imagelots_tools */
QIcon LIB_EXPORT JKQTPMathImageGetPaletteIcon(JKQTPMathImageColorPalette palette) ;



#ifndef NO_JKQTPLOTTER

/*! \brief if a class is derived from this class, it may use color bars
    \ingroup jkqtplotter_imagelots_tools
 */
class LIB_EXPORT JKQTPColorPaletteTools {
    public:

        JKQTPColorPaletteTools(JKQtBasePlotter *parent);
        virtual ~JKQTPColorPaletteTools();

        /*! \brief get list with all available palettes */
        static QStringList getPalettes() ;
        /*! \brief get list with all available palettes */
        static int getPalettesCount() ;
        /*! \brief get QIcon representing the given palette */
        static QIcon getPaletteIcon(int i) ;
        /*! \brief get QIcon representing the given palette */
        static QIcon getPaletteIcon(JKQTPMathImageColorPalette palette) ;
        /*! \brief get QIcon representing the given palette */
        static QImage getPaletteImage(int i, int width) ;
        /*! \brief get QIcon representing the given palette */
        static QImage getPaletteImage(JKQTPMathImageColorPalette palette, int width) ;

        /*! \brief get QIcon representing the given palette */
        static QIcon getPaletteKeyIcon(int i) ;
        /*! \brief get QIcon representing the given palette */
        static QIcon getPaletteKeyIcon(JKQTPMathImageColorPalette palette) ;
        /*! \brief get QIcon representing the given palette */
        static QImage getPaletteKeyImage(int i, int width, int height) ;
        /*! \brief get QIcon representing the given palette */
        static QImage getPaletteKeyImage(JKQTPMathImageColorPalette palette, int width, int height) ;



        void set_palette(int pal);

        /*! \brief if the graph plots outside the actual plot field of view (e.g. color bars, scale bars, ...)

            \note If you want to draw outside, then you'll also have to implement drawOutside()
         */
        void cbGetOutsideSize(JKQTPEnhancedPainter& painter, int& leftSpace, int& rightSpace, int& topSpace, int& bottomSpace);

        /*! \brief plots outside the actual plot field of view (e.g. color bars, scale bars, ...)

            \note If you want to draw outside, then you'll also have to implement getOutsideSize(), so enough space is reserved

            The four value supplied tell the method where to draw (inside one of the rectangles).
         */
        void cbDrawOutside(JKQTPEnhancedPainter& painter, QRect leftSpace, QRect rightSpace, QRect topSpace, QRect bottomSpace);


        void cbSetParent(JKQtBasePlotter* parent);


        /** \brief determine min/max data value of the image */
        virtual void cbGetDataMinMax(double& imin, double& imax)=0;


        virtual double getInternalDataMin() const ;
        virtual double getInternalDataMax() const ;


    protected:
        JKQtBasePlotter* cbParent;


        /** \brief top color bar visible */
        bool colorBarTopVisible;
        /** \brief right color bar visible */
        bool colorBarRightVisible;
        /** \brief name of the image displayed above color bar (may contain LaTeX markup!) */
        QString imageName;
        /** \brief font name when displaying imageName */
        QString imageNameFontName;
        /** \brief font size in points when displaying imageName */
        double imageNameFontSize;
        /** \brief palette for plotting an image */
        JKQTPMathImageColorPalette palette;
        /** \brief indicate whether to display a color bar */
        bool showColorBar;
        /** \brief width of the color bar */
        int colorBarWidth;
        /** \brief height of the color bar, as multiple of plotHeight */
        double colorBarRelativeHeight;
        /** \brief indicates whether to estimate min/max of the image automatically */
        bool autoImageRange;
        /** \brief image value range minimum */
        double imageMin;
        /** \brief image value range maximum */
        double imageMax;
        /** \brief offset between outside space border and color bar */
        int colorBarOffset;
        /** \brief which action to take if a color is below \a imageMin and \a autoImageRange \c ==false */
        JKQTPMathImageColorRangeFailAction rangeMinFailAction;
        /** \brief which action to take if a color is above \a imageMax and \a autoImageRange \c ==false */
        JKQTPMathImageColorRangeFailAction rangeMaxFailAction;
        /** \brief color to use for some settings of \a rangeMinFailAction */
        QColor rangeMinFailColor;
        /** \brief color to use for some settings of \a rangeMaxFailAction */
        QColor rangeMaxFailColor;
        /** \brief color to use for a not-a-number value */
        QColor nanColor;
        /** \brief color to use for an infinity value */
        QColor infColor;


        /** \brief object used for color bar axes
         *
         *  \note this axis has some kind of a special role. It is used to format color bar axes
         */
        JKQTPverticalIndependentAxis* colorBarRightAxis;
        JKQTPhorizontalIndependentAxis* colorBarTopAxis;



    public:

        /*! \brief sets the property palette to the specified \a __value. 
            \details Description of the parameter palette is: <BLOCKQUOTE>\copybrief palette </BLOCKQUOTE> 
            \see palette for more information */ 
        inline virtual void set_palette(const JKQTPMathImageColorPalette & __value)  
        {
            this->palette = __value;
        } 
        /*! \brief returns the property palette. 
            \details Description of the parameter palette is: <BLOCKQUOTE>\copybrief palette </BLOCKQUOTE> 
            \see palette for more information */ 
        inline virtual JKQTPMathImageColorPalette get_palette() const  
        {
            return this->palette; 
        }
        /*! \brief sets the property rangeMinFailAction to the specified \a __value. 
            \details Description of the parameter rangeMinFailAction is: <BLOCKQUOTE>\copybrief rangeMinFailAction </BLOCKQUOTE> 
            \see rangeMinFailAction for more information */ 
        inline virtual void set_rangeMinFailAction(const JKQTPMathImageColorRangeFailAction & __value)  
        {
            this->rangeMinFailAction = __value;
        } 
        /*! \brief returns the property rangeMinFailAction. 
            \details Description of the parameter rangeMinFailAction is: <BLOCKQUOTE>\copybrief rangeMinFailAction </BLOCKQUOTE> 
            \see rangeMinFailAction for more information */ 
        inline virtual JKQTPMathImageColorRangeFailAction get_rangeMinFailAction() const  
        {
            return this->rangeMinFailAction; 
        }
        /*! \brief sets the property rangeMaxFailAction to the specified \a __value. 
            \details Description of the parameter rangeMaxFailAction is: <BLOCKQUOTE>\copybrief rangeMaxFailAction </BLOCKQUOTE> 
            \see rangeMaxFailAction for more information */ 
        inline virtual void set_rangeMaxFailAction(const JKQTPMathImageColorRangeFailAction & __value)  
        {
            this->rangeMaxFailAction = __value;
        } 
        /*! \brief returns the property rangeMaxFailAction. 
            \details Description of the parameter rangeMaxFailAction is: <BLOCKQUOTE>\copybrief rangeMaxFailAction </BLOCKQUOTE> 
            \see rangeMaxFailAction for more information */ 
        inline virtual JKQTPMathImageColorRangeFailAction get_rangeMaxFailAction() const  
        {
            return this->rangeMaxFailAction; 
        }
        /*! \brief sets the property rangeMinFailColor to the specified \a __value. 
            \details Description of the parameter rangeMinFailColor is: <BLOCKQUOTE>\copybrief rangeMinFailColor </BLOCKQUOTE> 
            \see rangeMinFailColor for more information */ 
        inline virtual void set_rangeMinFailColor(const QColor & __value)  
        {
            this->rangeMinFailColor = __value;
        } 
        /*! \brief returns the property rangeMinFailColor. 
            \details Description of the parameter rangeMinFailColor is: <BLOCKQUOTE>\copybrief rangeMinFailColor </BLOCKQUOTE> 
            \see rangeMinFailColor for more information */ 
        inline virtual QColor get_rangeMinFailColor() const  
        {
            return this->rangeMinFailColor; 
        }
        /*! \brief sets the property rangeMaxFailColor to the specified \a __value. 
            \details Description of the parameter rangeMaxFailColor is: <BLOCKQUOTE>\copybrief rangeMaxFailColor </BLOCKQUOTE> 
            \see rangeMaxFailColor for more information */ 
        inline virtual void set_rangeMaxFailColor(const QColor & __value)  
        {
            this->rangeMaxFailColor = __value;
        } 
        /*! \brief returns the property rangeMaxFailColor. 
            \details Description of the parameter rangeMaxFailColor is: <BLOCKQUOTE>\copybrief rangeMaxFailColor </BLOCKQUOTE> 
            \see rangeMaxFailColor for more information */ 
        inline virtual QColor get_rangeMaxFailColor() const  
        {
            return this->rangeMaxFailColor; 
        }
        /*! \brief sets the property nanColor to the specified \a __value. 
            \details Description of the parameter nanColor is: <BLOCKQUOTE>\copybrief nanColor </BLOCKQUOTE> 
            \see nanColor for more information */ 
        inline virtual void set_nanColor(const QColor & __value)  
        {
            this->nanColor = __value;
        } 
        /*! \brief returns the property nanColor. 
            \details Description of the parameter nanColor is: <BLOCKQUOTE>\copybrief nanColor </BLOCKQUOTE> 
            \see nanColor for more information */ 
        inline virtual QColor get_nanColor() const  
        {
            return this->nanColor; 
        }
        /*! \brief sets the property infColor to the specified \a __value. 
            \details Description of the parameter infColor is: <BLOCKQUOTE>\copybrief infColor </BLOCKQUOTE> 
            \see infColor for more information */ 
        inline virtual void set_infColor(const QColor & __value)  
        {
            this->infColor = __value;
        } 
        /*! \brief returns the property infColor. 
            \details Description of the parameter infColor is: <BLOCKQUOTE>\copybrief infColor </BLOCKQUOTE> 
            \see infColor for more information */ 
        inline virtual QColor get_infColor() const  
        {
            return this->infColor; 
        }
        /*! \brief sets the property showColorBar to the specified \a __value. 
            \details Description of the parameter showColorBar is: <BLOCKQUOTE>\copybrief showColorBar </BLOCKQUOTE> 
            \see showColorBar for more information */ 
        inline virtual void set_showColorBar(bool __value)  
        {
            this->showColorBar = __value;
        } 
        /*! \brief returns the property showColorBar. 
            \details Description of the parameter showColorBar is: <BLOCKQUOTE>\copybrief showColorBar </BLOCKQUOTE> 
            \see showColorBar for more information */ 
        inline virtual bool get_showColorBar() const  
        {
            return this->showColorBar; 
        }
        /*! \brief sets the property colorBarWidth to the specified \a __value. 
            \details Description of the parameter colorBarWidth is: <BLOCKQUOTE>\copybrief colorBarWidth </BLOCKQUOTE> 
            \see colorBarWidth for more information */ 
        inline virtual void set_colorBarWidth(int __value)  
        {
            this->colorBarWidth = __value;
        } 
        /*! \brief returns the property colorBarWidth. 
            \details Description of the parameter colorBarWidth is: <BLOCKQUOTE>\copybrief colorBarWidth </BLOCKQUOTE> 
            \see colorBarWidth for more information */ 
        inline virtual int get_colorBarWidth() const  
        {
            return this->colorBarWidth; 
        }
        /*! \brief sets the property colorBarOffset to the specified \a __value. 
            \details Description of the parameter colorBarOffset is: <BLOCKQUOTE>\copybrief colorBarOffset </BLOCKQUOTE> 
            \see colorBarOffset for more information */ 
        inline virtual void set_colorBarOffset(int __value)  
        {
            this->colorBarOffset = __value;
        } 
        /*! \brief returns the property colorBarOffset. 
            \details Description of the parameter colorBarOffset is: <BLOCKQUOTE>\copybrief colorBarOffset </BLOCKQUOTE> 
            \see colorBarOffset for more information */ 
        inline virtual int get_colorBarOffset() const  
        {
            return this->colorBarOffset; 
        }
        /*! \brief sets the property colorBarRelativeHeight to the specified \a __value. 
            \details Description of the parameter colorBarRelativeHeight is: <BLOCKQUOTE>\copybrief colorBarRelativeHeight </BLOCKQUOTE> 
            \see colorBarRelativeHeight for more information */ 
        inline virtual void set_colorBarRelativeHeight(double __value)  
        {
            this->colorBarRelativeHeight = __value;
        } 
        /*! \brief returns the property colorBarRelativeHeight. 
            \details Description of the parameter colorBarRelativeHeight is: <BLOCKQUOTE>\copybrief colorBarRelativeHeight </BLOCKQUOTE> 
            \see colorBarRelativeHeight for more information */ 
        inline virtual double get_colorBarRelativeHeight() const  
        {
            return this->colorBarRelativeHeight; 
        }
        /*! \brief sets the property imageMin to the specified \a __value. 
            \details Description of the parameter imageMin is: <BLOCKQUOTE>\copybrief imageMin </BLOCKQUOTE> 
            \see imageMin for more information */ 
        inline virtual void set_imageMin(double __value)  
        {
            this->imageMin = __value;
        } 
        /*! \brief returns the property imageMin. 
            \details Description of the parameter imageMin is: <BLOCKQUOTE>\copybrief imageMin </BLOCKQUOTE> 
            \see imageMin for more information */ 
        inline virtual double get_imageMin() const  
        {
            return this->imageMin; 
        }
        /*! \brief sets the property imageMax to the specified \a __value. 
            \details Description of the parameter imageMax is: <BLOCKQUOTE>\copybrief imageMax </BLOCKQUOTE> 
            \see imageMax for more information */ 
        inline virtual void set_imageMax(double __value)  
        {
            this->imageMax = __value;
        } 
        /*! \brief returns the property imageMax. 
            \details Description of the parameter imageMax is: <BLOCKQUOTE>\copybrief imageMax </BLOCKQUOTE> 
            \see imageMax for more information */ 
        inline virtual double get_imageMax() const  
        {
            return this->imageMax; 
        }
        /*! \brief sets the property autoImageRange to the specified \a __value. 
            \details Description of the parameter autoImageRange is: <BLOCKQUOTE>\copybrief autoImageRange </BLOCKQUOTE> 
            \see autoImageRange for more information */ 
        inline virtual void set_autoImageRange(bool __value)  
        {
            this->autoImageRange = __value;
        } 
        /*! \brief returns the property autoImageRange. 
            \details Description of the parameter autoImageRange is: <BLOCKQUOTE>\copybrief autoImageRange </BLOCKQUOTE> 
            \see autoImageRange for more information */ 
        inline virtual bool get_autoImageRange() const  
        {
            return this->autoImageRange; 
        }
        /*! \brief sets the property imageName to the specified \a __value. 
            \details Description of the parameter imageName is: <BLOCKQUOTE>\copybrief imageName </BLOCKQUOTE> 
            \see imageName for more information */ 
        inline virtual void set_imageName(const QString & __value)  
        {
            this->imageName = __value;
        } 
        /*! \brief returns the property imageName. 
            \details Description of the parameter imageName is: <BLOCKQUOTE>\copybrief imageName </BLOCKQUOTE> 
            \see imageName for more information */ 
        inline virtual QString get_imageName() const  
        {
            return this->imageName; 
        }
        /*! \brief sets the property imageNameFontName to the specified \a __value. 
            \details Description of the parameter imageNameFontName is: <BLOCKQUOTE>\copybrief imageNameFontName </BLOCKQUOTE> 
            \see imageNameFontName for more information */ 
        inline virtual void set_imageNameFontName(const QString & __value)  
        {
            this->imageNameFontName = __value;
        } 
        /*! \brief returns the property imageNameFontName. 
            \details Description of the parameter imageNameFontName is: <BLOCKQUOTE>\copybrief imageNameFontName </BLOCKQUOTE> 
            \see imageNameFontName for more information */ 
        inline virtual QString get_imageNameFontName() const  
        {
            return this->imageNameFontName; 
        }
        /*! \brief sets the property imageNameFontSize to the specified \a __value. 
            \details Description of the parameter imageNameFontSize is: <BLOCKQUOTE>\copybrief imageNameFontSize </BLOCKQUOTE> 
            \see imageNameFontSize for more information */ 
        inline virtual void set_imageNameFontSize(double __value)  
        {
            this->imageNameFontSize = __value;
        } 
        /*! \brief returns the property imageNameFontSize. 
            \details Description of the parameter imageNameFontSize is: <BLOCKQUOTE>\copybrief imageNameFontSize </BLOCKQUOTE> 
            \see imageNameFontSize for more information */ 
        inline virtual double get_imageNameFontSize() const  
        {
            return this->imageNameFontSize; 
        }
        /*! \brief returns the property colorBarRightAxis. 
            \details Description of the parameter colorBarRightAxis is:  <BLOCKQUOTE>\copybrief colorBarRightAxis </BLOCKQUOTE>. 
            \see colorBarRightAxis for more information */ 
        inline JKQTPverticalIndependentAxis* get_colorBarRightAxis() const { 
            return this->colorBarRightAxis; 
        }
        /*! \brief returns the property colorBarTopAxis. 
            \details Description of the parameter colorBarTopAxis is:  <BLOCKQUOTE>\copybrief colorBarTopAxis </BLOCKQUOTE>. 
            \see colorBarTopAxis for more information */ 
        inline JKQTPhorizontalIndependentAxis* get_colorBarTopAxis() const { 
            return this->colorBarTopAxis; 
        }
        /*! \brief sets the property colorBarTopVisible to the specified \a __value. 
            \details Description of the parameter colorBarTopVisible is: <BLOCKQUOTE>\copybrief colorBarTopVisible </BLOCKQUOTE> 
            \see colorBarTopVisible for more information */ 
        inline virtual void set_colorBarTopVisible(bool __value)  
        {
            this->colorBarTopVisible = __value;
        } 
        /*! \brief returns the property colorBarTopVisible. 
            \details Description of the parameter colorBarTopVisible is: <BLOCKQUOTE>\copybrief colorBarTopVisible </BLOCKQUOTE> 
            \see colorBarTopVisible for more information */ 
        inline virtual bool get_colorBarTopVisible() const  
        {
            return this->colorBarTopVisible; 
        }
        /*! \brief sets the property colorBarRightVisible to the specified \a __value. 
            \details Description of the parameter colorBarRightVisible is: <BLOCKQUOTE>\copybrief colorBarRightVisible </BLOCKQUOTE> 
            \see colorBarRightVisible for more information */ 
        inline virtual void set_colorBarRightVisible(bool __value)  
        {
            this->colorBarRightVisible = __value;
        } 
        /*! \brief returns the property colorBarRightVisible. 
            \details Description of the parameter colorBarRightVisible is: <BLOCKQUOTE>\copybrief colorBarRightVisible </BLOCKQUOTE> 
            \see colorBarRightVisible for more information */ 
        inline virtual bool get_colorBarRightVisible() const  
        {
            return this->colorBarRightVisible; 
        }

};
#endif


#endif // JKQTPIMAGETOOLS_H