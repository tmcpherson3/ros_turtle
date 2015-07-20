#ifndef SEEK_TURTLE
#define SEEK_TURTLE

#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Spawn.h"

class Seeker
{
	public:
		Seeker();
		void computeAndPublishVelCmd(turtlesim::Pose targetPose);
		void runSeekerLoop();
	private:
		ros::Subscriber poseSub;
		ros::NodeHandle n;
		ros::Publisher seekerCmdPub;
		ros::ServiceClient spawnClient;
};
#endif
