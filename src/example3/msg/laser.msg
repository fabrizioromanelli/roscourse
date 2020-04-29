# Single scan from a planar laser range-finder

Header header            # timestamp in the header is the acquisition time of 
                         # the first ray in the scan.

float32 angle_min        # start angle of the scan [rad]
float32 angle_max        # end angle of the scan [rad]
float32 angle_increment  # angular distance between measurements [rad]

float32 range_min        # minimum range value [m]
float32 range_max        # maximum range value [m]

float32[] ranges         # range data [m]