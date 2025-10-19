

namespace simulation {
    void simulate(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *accelerationTime, double *inertiaTime, double *fallTime, double *totalTime,
        double *maxHeight, double *maxSpeed
    );
    void acceleration(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *speed, double *space, double *time);
    void inertia(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *speed, double *space, double *time);
    void fall(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *speed, double *space, double *time);
}

namespace simulation {
    void simulate(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *accelerationTime, double *inertiaTime, double *fallTime, double *totalTime,
        double *maxHeight, double *maxSpeed
    ) {
        double speed, space, time;

        simulation::acceleration(mass, engineThrust, gravityAcceleration, thrustTime, angleOfAttack, &speed, &space, &time);
        *accelerationTime = time;

        simulation::inertia(mass, engineThrust, gravityAcceleration, thrustTime, angleOfAttack, &speed, &space, &time);
        *inertiaTime = time;
        *maxHeight = space;

        simulation::fall(mass, engineThrust, gravityAcceleration, thrustTime, angleOfAttack, &speed, &space, &time);
        *fallTime = time;
        *maxSpeed = speed;

        *totalTime = *accelerationTime + *inertiaTime + *fallTime;
        return;
    }

    void acceleration(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *speed, double *space, double *time
    ) {
        double rocketAcceleration = engineThrust / mass; // f=ma => a=f/m
        double resultingAcceleration = rocketAcceleration - gravityAcceleration;
        double speed0 = *speed;
        double space0 = *space;

        *time = thrustTime; // fixed by thrustTime
        *speed = resultingAcceleration * (*time) + speed0; // v(t)
        *space = ( resultingAcceleration * std::pow((*time), 2) ) / 2 + (speed0) * (*time) + space0; // s(t)
        return;
    }

    void inertia(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *speed, double *space, double *time
    ) {
        double resultingAcceleration = -gravityAcceleration;
        double speed0 = *speed;
        double space0 = *space;

        *speed = 0; // fixed by speed = 0 (the max point)
        *time = -speed0 / resultingAcceleration; // v(t) = 0, isoling time
        *space = ( resultingAcceleration * std::pow((*time), 2) ) / 2 + (speed0) * (*time) + space0; // s(t)
        return;
    }

    void fall(
        double mass, double engineThrust, double gravityAcceleration, double thrustTime, double angleOfAttack,
        double *speed, double *space, double *time
    ) {
        double resultingAcceleration = -gravityAcceleration;
        double speed0 = 0;
        double space0 = *space;

        *space = 0; // fixed by space = 0 (when touch ground)
        *time = std::sqrt(-(2 * space0) / resultingAcceleration); // s(t) = 0, isoling time
        *speed = resultingAcceleration * (*time); // v(t)
        return;
    }
}