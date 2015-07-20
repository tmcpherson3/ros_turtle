#include "Seeker.h"
#include <string>

// Constructor
Seeker::Seeker()
{	
	// Get node handle
	// ros::NodeHandle n; <-- declared in header

	// Subscribe to first turtle pose
	poseSub = n.subscribe("turtle1/pose", 10, &Seeker::computeAndPublishVelCmd, this);

	// Advertise cmd_vel topic for seeker turtle
	seekerCmdPub = n.advertise<geometry_msgs::Twist>("seekerTurtle/cmd_vel", 10);
	
	// spawn the seeker turtle
	spawnClient = n.serviceClient<turtlesim::Spawn>("spawn");
	turtlesim::Spawn spawnService;
	spawnService.request.x = 5.0;
	spawnService.request.y = 3.0;
	spawnService.request.theta = 0.0;
	spawnService.request.name = "seekerTurtle";
	if (spawnClient.call(spawnService))
	{
		ROS_INFO("Creating seeker turtle");
	}
	else
	{
		ROS_INFO("Failed to call service turtlesim Spawn when creating seeker turtle");
	}
}

void Seeker::runSeekerLoop()
{
	ros::spin();
}

void Seeker::computeAndPublishVelCmd(const turtlesim::Pose targetPose)
{
	// placeholder for real algorithm
	// just copy the other turtle for now
	geometry_msgs::Twist cmd;
	cmd.angular.z = targetPose.angular_velocity;
	cmd.linear.x = targetPose.linear_velocity;
	// then publish it to the topic
	this->seekerCmdPub.publish(cmd);
	return;
}
