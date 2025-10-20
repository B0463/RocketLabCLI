

namespace simulation {
    void simulate(
        double mass, double engineThrust, double gravityAccelerationMagnitude, double thrustTime, double angleOfAttack,
        double *accelerationTime, double *inertiaTime, double *fallTime, double *totalTime,
        double *maxHeight, double *range, double *maxVelocity, double *fallVelocity, double *fallAngle);
    void acceleration(
        double mass, double engineThrust, double gravityAcceleration[2], double thrustTime, double angleOfAttack,
        double velocity[2], double space[2], double *time);
    void inertia(
        double mass, double engineThrust, double gravityAcceleration[2], double thrustTime, double angleOfAttack,
        double velocity[2], double space[2], double *time);
    void fall(
        double mass, double engineThrust, double gravityAcceleration[2], double thrustTime, double angleOfAttack,
        double velocity[2], double space[2], double *time);
    double getMagnitudeX(double magnitude, double angle);
    double getMagnitudeY(double magnitude, double angle);
    void getVectorPolar(double vector[2], double *magnitude, double *angle);
}

namespace simulation {
    void simulate(
        double mass, double engineThrust, double gravityAccelerationMagnitude, double thrustTime, double angleOfAttack,
        double *accelerationTime, double *inertiaTime, double *fallTime, double *totalTime,
        double *maxHeight, double *range, double *maxVelocity, double *fallVelocity, double *fallAngle
    ) {
        double velocity[2], space[2], time;

        double gravityAcceleration[2] = {
            getMagnitudeX(gravityAccelerationMagnitude, -90),
            getMagnitudeY(gravityAccelerationMagnitude, -90)
        };

        simulation::acceleration(mass, engineThrust, gravityAcceleration, thrustTime, angleOfAttack, velocity, space, &time);
        *accelerationTime = time;

        getVectorPolar(velocity, maxVelocity, nullptr);

        simulation::inertia(mass, engineThrust, gravityAcceleration, thrustTime, angleOfAttack, velocity, space, &time);
        *inertiaTime = time;
        
        *maxHeight = space[Y];

        simulation::fall(mass, engineThrust, gravityAcceleration, thrustTime, angleOfAttack, velocity, space, &time);
        *fallTime = time;

        getVectorPolar(velocity, fallVelocity, fallAngle);
        *range = space[X];

        *totalTime = *accelerationTime + *inertiaTime + *fallTime;
        return;
    }

    void acceleration(
        double mass, double engineThrust, double gravityAcceleration[2], double thrustTime, double angleOfAttack,
        double velocity[2], double space[2], double *time
    ) {
        double rocketAccelerationMagnitude = engineThrust / mass; // f=ma => a=f/m
        double rocketAcceleration[2] = {
            getMagnitudeX(rocketAccelerationMagnitude, angleOfAttack),
            getMagnitudeY(rocketAccelerationMagnitude, angleOfAttack)
        };

        double resultingAcceleration[2] = {
            rocketAcceleration[X] + gravityAcceleration[X],
            rocketAcceleration[Y] + gravityAcceleration[Y]
        };

        double velocity0[2] = { velocity[X], velocity[Y] };
        double space0[2] = { space[X], space[Y] };

        *time = thrustTime; // fixed by thrustTime

        velocity[X] = resultingAcceleration[X] * (*time) + velocity0[X]; // Vx(t)
        space[X] = ( resultingAcceleration[X] * std::pow((*time), 2) ) / 2 + velocity0[X] * (*time) + space0[X]; // Sx(t)

        velocity[Y] = resultingAcceleration[Y] * (*time) + velocity0[Y]; // Vy(t)
        space[Y] = ( resultingAcceleration[Y] * std::pow((*time), 2) ) / 2 + velocity0[Y] * (*time) + space0[Y]; // Sy(t)
        return;
    }

    void inertia(
        double mass, double engineThrust, double gravityAcceleration[2], double thrustTime, double angleOfAttack,
        double velocity[2], double space[2], double *time
    ) {
        double resultingAcceleration[2] = { gravityAcceleration[X], gravityAcceleration[Y] };
        double velocity0[2] = { velocity[X], velocity[Y] };
        double space0[2] = { space[X], space[Y] };



        velocity[Y] = 0; // fixed by velocity[Y] = 0 (the max point)
        *time = -velocity0[Y] / resultingAcceleration[Y]; // Vy(t) = 0, isoling time
        space[Y] = ( resultingAcceleration[Y] * std::pow((*time), 2) ) / 2 + velocity0[Y] * (*time) + space0[Y]; // Sy(t)

        velocity[X] = resultingAcceleration[X] * (*time) + velocity0[X]; // Vx(t)
        space[X] = ( resultingAcceleration[X] * std::pow((*time), 2) ) / 2 + velocity0[X] * (*time) + space0[X]; // Sx(t)
        return;
    }

    void fall(
        double mass, double engineThrust, double gravityAcceleration[2], double thrustTime, double angleOfAttack,
        double velocity[2], double space[2], double *time
    ) {
        double resultingAcceleration[2] = { gravityAcceleration[X], gravityAcceleration[Y] };
        double velocity0[2] = { velocity[X], velocity[Y] };
        double space0[2] = { space[X], space[Y] };

        space[Y] = 0; // fixed by spaceY = 0 (when touch ground)
        *time = std::sqrt(-(2 * space0[Y]) / resultingAcceleration[Y]); // Sy(t) = 0, isoling time
        velocity[Y] = resultingAcceleration[Y] * (*time) + velocity0[Y]; // Vy(t)

        velocity[X] = resultingAcceleration[X] * (*time) + velocity0[X]; // Vx(t)
        space[X] = resultingAcceleration[X] * std::pow((*time), 2) / 2 + velocity0[X] * (*time) + space0[X]; // Sx(t)
        return;
    }

    double getMagnitudeX(double magnitude, double angle) {
        return (std::cos(angle *  M_PI / 180.0) * magnitude);
    }
    double getMagnitudeY(double magnitude, double angle) {
        return (std::sin(angle *  M_PI / 180.0) * magnitude);
    }
    void getVectorPolar(double vector[2], double *magnitude, double *angle) {
        if(angle) *angle = std::atan2( vector[Y], vector[X] ) * 180.0 / M_PI;
        if(magnitude) *magnitude = std::sqrt( std::pow(vector[X], 2) + std::pow(vector[Y], 2) );
        return;
    }
}