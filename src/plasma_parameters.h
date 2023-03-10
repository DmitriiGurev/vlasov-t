#pragma once

#include <string>
#include <vector>

#include "constants.h"
#include "mesh.h"
#include "typedefs.h"
#include "velocity_grid.h"

enum class ParticleType
{
    Electron,
    Ion,
    Neutral
};

class PlasmaParameters
{
public:
    PlasmaParameters(const Mesh* mesh, const VelocityGrid<Tensor>* vGrid) :
        _mesh(mesh), _vGrid(vGrid) {}

    struct Maxwell
    {
        std::vector<double> physDensity;
        double temperature;
        std::array<double, 3> averageV;
    };

    template <typename ParamsPDF>
    void SetPDF(const ParamsPDF& parameters);

    std::vector<double> Density() const;

public:
    ParticleType species;
    double       mass;
    double       charge;

    std::vector<Tensor> pdf;

private:
    const Mesh* _mesh;
    const VelocityGrid<Tensor>* _vGrid;
};

std::vector<double> ConstDensity(const Mesh* mesh, double density);