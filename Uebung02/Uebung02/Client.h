/* File: Client.h
* Creator: Paul Engelhardt
*/
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class IEmployeeManager; // Forward declaration to avoid circular dependencies

/// <summary>
/// Class representing a client that tests the EmployeeManager.
/// </summary>
class Client {
public:
    /// <summary>
    /// Constructor for the Client class.
    /// </summary>
    /// <param name="manager">A pointer to the EmployeeManager used for testing.</param>
    Client(IEmployeeManager* manager) : mManager(manager) {};

    /// <summary>
    /// Perform testing on the EmployeeManager.
    /// </summary>
    void ManagerTest();

private:
    IEmployeeManager* mManager; ///< <summary> A pointer to the EmployeeManager for testing. </summary>
};

#endif
