/* File: PieceWorker.h
* Creator: Harald Kiss
*/
#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include "Employee.h"

/// <summary>
/// Class representing a Piece Worker employee.
/// </summary>
class PieceWorker : public Employee {
public:
    /// <summary>
    /// Constructor for Piece Worker.
    /// </summary>
    /// <param name="Name">The first name of the Piece Worker.</param>
    /// <param name="Surname">The last name of the Piece Worker.</param>
    /// <param name="InsuranceNumber">The social insurance number of the Piece Worker.</param>
    /// <param name="EntryYear">The year when the Piece Worker joined the company.</param>
    /// <param name="PieceValue">The value of each piece produced by the Piece Worker.</param>
    /// <param name="ProducedPieces">The number of pieces produced by the Piece Worker.</param>
    PieceWorker(std::string Name, std::string Surname, size_t InsuranceNumber, size_t EntryYear, float PieceValue, size_t ProducedPieces)
        : Employee{ Name, Surname, InsuranceNumber, EntryYear }, mPieceValue{ PieceValue }, mProducedPieces{ ProducedPieces } {};

    /// <summary>
    /// Get the provision for the Piece Worker.
    /// </summary>
    /// <returns>The provision for the Piece Worker.</returns>
    float GetProvision();

    /// <summary>
    /// Get the base monthly salary for the Piece Worker.
    /// </summary>
    /// <returns>The base monthly salary based on the value of produced pieces.</returns>
    float GetBaseSalary();

    /// <summary>
    /// Calculate the total monthly salary for the Piece Worker.
    /// </summary>
    /// <returns>The total monthly salary, including any additional provisions.</returns>
    float CalcSalary() override { return GetProvision() + GetBaseSalary(); };

    /// <summary>
    /// Get the number of pieces produced by the Piece Worker.
    /// </summary>
    /// <returns>The number of pieces produced by the Piece Worker.</returns>
    size_t GetProducedPieces() override;

    /// <summary>
    /// Print information about the Piece Worker.
    /// </summary>
    void Print() override;

    /// <summary>
    /// Set the number of pieces produced by the Piece Worker.
    /// </summary>
    void SetPieces();

    /// <summary>
    /// Get the type of the employee (Piece Worker).
    /// </summary>
    /// <returns>The type of the employee (Piece Worker).</returns>
    EmployeeType GetType() override;

private:
    size_t mProducedPieces; ///< <summary> The number of pieces produced by the Piece Worker. </summary>
    float mPieceValue; ///< <summary> The value of each piece produced by the Piece Worker. </summary>
};

#endif
