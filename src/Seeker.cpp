#include "Seeker.h"
#include <string>

// Constructor
Seeker::Seeker()
{	
	// Initialize ROS node	
	ros::init(argc, argv, "seek_turtle_node");
	
	// Get node handle
	// ros::NodeHandle n; <-- declared in header

	// Subscribe to first turtle pose
	poseSub = n.subscribe("turtle1/Pose", 10, &Seeker::computeAndPublishVelCmd, this);

	// Advertise cmd_vel topic for seeker turtle
	seekerCmdPub = n.advertise<geomerty_msgs::Twist>("turtle2/cmd_vel", 10);
	
	// spawn the seeker turtle
	spawnClient = n.serviceClient<turtlesim::Spawn>("spawn");
	turtlesim::Spawn spawnService;
	spawnService.request.x = 0.0;
	spawnService.request.y = 0.0;
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

void computeAndPublishVelCmd(const turtlesim::Pose targetPose)
{
	// placeholder for real algorithm
	// just copy the other turtle for now
	geometry_msgs::Twist cmd;
	cmd.angular.z = pose.angular_velocity;
	cmd.linear.x = pose.linear_velocity;
	// then publish it to the topic
	seekerCmdPub.publish(cmd);
}
