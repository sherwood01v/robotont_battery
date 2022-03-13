from numpy import NaN
import rospy
from sensor_msgs.msg import BatteryState
from std_msgs.msg import Float32MultiArray

pub_batterystate = rospy.Publisher('batterystate', BatteryState, queue_size=40)

def callback(data):
    global values
    values = data.data
    battery = BatteryState()
    POWER_SUPPLY_TECHNOLOGY_LIPO = 3
    current_time = rospy.get_rostime()
    battery.header.stamp.secs = current_time.secs
    battery.header.stamp.nsecs = current_time.nsecs
    battery.voltage = values[3]
    battery.current = (NaN)
    battery.charge = (NaN)
    battery.capacity = (NaN)
    battery.temperature = (NaN)
    battery.design_capacity = (3.8)
    battery.percentage = (values[3]-14.8)/2
    battery.power_supply_technology = POWER_SUPPLY_TECHNOLOGY_LIPO
    battery.present = True
    battery.cell_voltage = [values[4], values[5], values[6], values[7]]
    rospy.loginfo(battery)
    pub_batterystate.publish(battery)

def arduino_listener():

    rospy.init_node('arduino_listener', anonymous=True)
    rospy.Subscriber("arduino_values", Float32MultiArray, callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        arduino_listener()
    except rospy.ROSInterruptException:
        pass