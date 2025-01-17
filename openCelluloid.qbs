import qbs
import qbs.Process
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import "../../../libs/openFrameworksCompiled/project/qtcreator/ofApp.qbs" as ofApp

Project{
    property string of_root: '../../..'

    ofApp {
        name: { return FileInfo.baseName(sourceDirectory) }

        files: [
            "src/serial.cpp",
            "src/camera.cpp",
            "src/gui.cpp",
            "src/main.cpp",
            "src/ofApp.cpp",
            "src/ofApp.h",
            "src/graphics.cpp"
        ]

        of.addons: [
            'ofxBlackmagic',
            'ofxGuiExtended',
            'ofxSerial',
            'ofxPoco',
            'ofxIO',
            'ofxGrafica'
            //'ofxOpenCelluloid'
        ]

        // This project is using addons.make to include the addons
        // since it was imported from old code. To change it to include
        // the addons from the qbs file change the following lines to
        // the list of used addons in array format. eg:
        //
        // of.addons: [
        //     'ofxGui',
        //     'ofxOpenCv',
        // ]

        // additional flags for the project. the of module sets some
        // flags by default to add the core libraries, search paths...
        // this flags can be augmented through the following properties:
        of.pkgConfigs: []       // list of additional system pkgs to include
        of.includePaths: []     // include search paths
        of.cFlags: ['-std=c++11',
                    '-Wno-multichar',
                    '-I',
                    '-fno-rtti',
                    '-Wall',
                    '-g']           // flags passed to the c compiler
        of.cxxFlags: ['-std=c++0x',
                      '-pthread']         // flags passed to the c++ compiler
        of.linkerFlags: ['-lm',
                         '-ldl',
                         '-lpthread',
                         '-lpng']      // flags passed to the linker
        of.defines: []          // defines are passed as -D to the compiler
        // and can be checked with #ifdef or #if in the code
        of.frameworks: []       // osx only, additional frameworks to link with the project
        of.staticLibraries: ['/usr/lib/x86_64-linux-gnu/libpng.so']  // static libraries
        of.dynamicLibraries: [] // dynamic libraries

        // create a console window when the application start
        consoleApplication: false

        // other flags can be set through the cpp module: http://doc.qt.io/qbs/cpp-module.html
        // eg: this will enable ccache when compiling
        //
        // cpp.compilerWrapper: 'ccache'

        Depends{
            name: "cpp"
        }

        // common rules that parse the include search paths, core libraries...
        Depends{
            name: "of"
        }

        // dependency with the OF library
        Depends{
            name: "openFrameworks"
        }
    }

    property bool makeOF: true  // use makfiles to compile the OF library
    // will compile OF only once for all your projects
    // otherwise compiled per project with qbs

    property bool precompileOfMain: false  // precompile ofMain.h
    // faster to recompile when including ofMain.h
    // but might use a lot of space per project

    references: [FileInfo.joinPaths(of_root, "/libs/openFrameworksCompiled/project/qtcreator/openFrameworks.qbs")]
}
