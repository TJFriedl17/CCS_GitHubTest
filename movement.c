#include "movement.h"
#include "uart-interrupt.h"
void bump(oi_t *sensor_data, double centimeters)
{

    double sum = 0;

    oi_setWheels(500, 500); // move forward; full speed
    while (sum < centimeters)
    {
        oi_update(sensor_data); // get current state of all sensors
        if (sensor_data->bumpLeft)
        { // respond to left bumper being pressed
            move_backward(sensor_data, -150);

            turn_left(sensor_data, -90); // i flipped turn left and turn right in both of the if statements
            move_forward(sensor_data, 250);

            turn_right(sensor_data, 90);
            bump(sensor_data, centimeters - sum + 150);
            // move_forward(sensor_data, centimeters + 150 - sum); // move forward the goal distance (centimeters) - the distance already traveled before bump (sum2)
            // + the distance removed from moving back in this case 150 cm
        } //end of bumpleft if
        if (sensor_data->bumpRight)
        {
            move_backward(sensor_data, -150);
            turn_right(sensor_data, 90);
            move_forward(sensor_data, 250);
            turn_left(sensor_data, -90);
            //  move_forward(sensor_data, centimeters + 150 - sum); // move forward the goal distance (centimeters) - the distance already traveled before bump (sum)
            // + the distance removed from moving back in this case 150 cm

            bump(sensor_data, centimeters - sum + 150);
        }                                                  //end of bumpright if

        sum += sensor_data->distance;

        lcd_printf("%f", sum);

    }                                                        //end of while loop
    oi_setWheels(0, 0); // stop
} // END of bump function

void turn_left(oi_t *sensor_data, int angle)
{

    double sum = 0;
    oi_setWheels(100, -100); // move forward; full speed
    while (sum < angle)
    {
        oi_update(sensor_data);
        sum += sensor_data->angle;
        //lcd_printf("%f", sum);
    }
    oi_setWheels(0, 0); // stop

}

void turn_right(oi_t *sensor_data, int angle)
{

    double sum = 0;
    double negAngle = 0 - angle;

    oi_setWheels(-100, 100); // move forward; full speed
    while (sum > negAngle)
    {
        oi_update(sensor_data);
        sum += sensor_data->angle;
        //lcd_printf("%f", sum);
    }
    oi_setWheels(0, 0); // stop

}

void move_forward(oi_t *sensor_data, int centimeters)
{
    double sum = 0;
    oi_setWheels(500, 500);
    while (sum < centimeters)
    {
        oi_update(sensor_data);
        sum += sensor_data->distance;
        // lcd_printf("%f", sum);
    }
    oi_setWheels(0, 0); // stop
}

void move_backward(oi_t *sensor_data, int centimeters)
{
    double sum = 0;
    oi_setWheels(-500, -500);
    while (sum > centimeters)
    {
        oi_update(sensor_data);
        sum += sensor_data->distance;
        //  lcd_printf("%f", sum);
    }
    oi_setWheels(0, 0); // stop
}

void printToPutty(char str[], int degrees, float distance)
{
    int i = 0;
    sprintf(str, "\n Degrees: %d \t Distance: %f (cm) \n\r", degrees, distance);
    while (str[i] != 0)
    {
        cyBot_sendByte(str[i]);
        i++;
    }
}

void printToPuttyObject(char str[], int count, int angle, int width,
                        float distance)
{
    int i = 0;
    sprintf(str, "\t Object#: %d Angle: %d Width: %d Distance: %f \n\r", count,
            angle, width, distance);
    while (str[i] != 0)
    {
        cyBot_sendByte(str[i]);
        i++;
    }
}

// void printToPuttyWidth(char str[], int count, int width) {
//     int i = 0;
//             sprintf(str, "\t\t\t\t\t Object #: %d Width: %d \n\r", count, width);
//             while (str[i] != 0) {
//                 cyBot_sendByte(str[i]);
//                       i++;
//             }
// }

int findMinWidth(int arr[], int n)
{
    int i;
    int r = 0;
    int min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            r = i;
        }

    }
    return r;

}

