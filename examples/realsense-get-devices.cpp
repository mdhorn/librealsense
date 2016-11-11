// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2015 Intel Corporation. All Rights Reserved.

#include <librealsense/rs.hpp>
#include <iostream>
#include <iomanip>

int main() try
{
    //rs::log_to_console(rs::log_severity::warn);
    //rs::log_to_file(rs::log_severity::debug, "librealsense.log");

    // Obtain a list of devices currently present on the system
    rs::context ctx;
    int device_count = ctx.get_device_count();   
    if (!device_count) printf("No device detected. Is it plugged in?\n");

    for(int i = 0; i < device_count; ++i)
    {
        // Show the device name and information
        rs::device * dev;
        try { dev = ctx.get_device(i); } catch (...) {}
        std::cout << "device" << i << ":" << dev->get_name() << ", ";
        std::cout << "serial_no:" << dev->get_serial() << ", ";
        try { std::cout << "usb_port:" << dev->get_usb_port_id() ; } catch (...) {}
        std::cout << "\n";
    }

    return EXIT_SUCCESS;
}
catch(const rs::error & e)
{
    std::cerr << "RealSense error calling " << e.get_failed_function() << "(" << e.get_failed_args() << "):\n    " << e.what() << std::endl;
    return EXIT_FAILURE;
}
