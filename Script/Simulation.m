startup_rvc;
% define the robot manipulator
robot = SerialLink([ 
    Revolute('d', 0, 'a', 0, 'alpha', 0, 'modified') % First joint rotates around z-axis
    Revolute('d', 0, 'a', 1.5, 'alpha', pi/2, 'modified')   % Second joint changes z and x
    Revolute('d', 0, 'a', 1.5, 'alpha', 0, 'modified')   % Third joint changes z, x, and y
], 'name', 'Robot Arm');

% set the joint limits to reflect servo constraints
robot.qlim = [
    0, pi;    % joint 1 limits
    0, pi;    % joint 2 limits
    0, pi     % joint 3 limits
];

% generate trajectory
qf = [0 0 0];  % final joint angles
q0 = [pi/2 pi/4 pi/3];  % initial joint angles
steps = 50; % number of steps

% generate a trajectory from q0 to qf
trajectory = jtraj(q0, qf, steps);

% initialize the plot
figure;
robot.plot(trajectory(1, :));
hold on;

% initialize a variable to store the end-effector positions
end_effector_positions = zeros(steps, 3);

% plot the robot and the trajectory
for i = 1:steps
    robot.plot(trajectory(i, :));
    
    % calculate the end-effector position at each step
    end_effector_pos = robot.fkine(trajectory(i, :));
    end_effector_positions(i, :) = end_effector_pos(1:3, 4)';
    
    % plot a line connecting the end-effector positions
    if i > 1
        plot3(end_effector_positions(i-1:i, 1), ...
              end_effector_positions(i-1:i, 2), ...
              end_effector_positions(i-1:i, 3), 'b', 'LineWidth', 1.5);
    end
    
    drawnow;
    pause(0.1);
end