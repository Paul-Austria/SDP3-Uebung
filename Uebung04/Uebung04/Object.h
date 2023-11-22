/** @file
* @brief Declaration of the Object class
* @details Defines an abstract Object class. Created by Paul Engelhart.
*/

#ifndef OBJECT_H
#define OBJECT_H

/** @brief Abstract Object class. */
class Object {

public:

    /** @brief Virtual destructor for Object. */
    virtual ~Object() = 0;

protected:

    /** @brief Default constructor for Object. */
    Object() = default;

private:

};

#endif
