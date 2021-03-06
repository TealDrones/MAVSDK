// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/geofence/geofence.proto)

#include <iomanip>

#include "geofence_impl.h"
#include "plugins/geofence/geofence.h"

namespace mavsdk {

using Point = Geofence::Point;
using Polygon = Geofence::Polygon;

Geofence::Geofence(System& system) : PluginBase(), _impl{new GeofenceImpl(system)} {}

Geofence::~Geofence() {}

void Geofence::upload_geofence_async(std::vector<Polygon> polygons, const ResultCallback callback)
{
    _impl->upload_geofence_async(polygons, callback);
}

Geofence::Result Geofence::upload_geofence(std::vector<Polygon> polygons) const
{
    return _impl->upload_geofence(polygons);
}

bool operator==(const Geofence::Point& lhs, const Geofence::Point& rhs)
{
    return ((std::isnan(rhs.latitude_deg) && std::isnan(lhs.latitude_deg)) ||
            rhs.latitude_deg == lhs.latitude_deg) &&
           ((std::isnan(rhs.longitude_deg) && std::isnan(lhs.longitude_deg)) ||
            rhs.longitude_deg == lhs.longitude_deg);
}

std::ostream& operator<<(std::ostream& str, Geofence::Point const& point)
{
    str << std::setprecision(15);
    str << "point:" << '\n' << "{\n";
    str << "    latitude_deg: " << point.latitude_deg << '\n';
    str << "    longitude_deg: " << point.longitude_deg << '\n';
    str << '}';
    return str;
}

std::ostream& operator<<(std::ostream& str, Geofence::Polygon::Type const& type)
{
    switch (type) {
        case Geofence::Polygon::Type::Inclusion:
            return str << "Type Inclusion";
        case Geofence::Polygon::Type::Exclusion:
            return str << "Type Exclusion";
        default:
            return str << "Unknown";
    }
}
bool operator==(const Geofence::Polygon& lhs, const Geofence::Polygon& rhs)
{
    return (rhs.points == lhs.points) && (rhs.type == lhs.type);
}

std::ostream& operator<<(std::ostream& str, Geofence::Polygon const& polygon)
{
    str << std::setprecision(15);
    str << "polygon:" << '\n' << "{\n";
    str << "    points: [";
    for (auto it = polygon.points.begin(); it != polygon.points.end(); ++it) {
        str << *it;
        str << (it + 1 != polygon.points.end() ? ", " : "]\n");
    }
    str << "    type: " << polygon.type << '\n';
    str << '}';
    return str;
}

const char* Geofence::result_str(Geofence::Result result)
{
    switch (result) {
        case Geofence::Result::Unknown:
            return "Unknown result";
        case Geofence::Result::Success:
            return "Request succeeded";
        case Geofence::Result::Error:
            return "Error";
        case Geofence::Result::TooManyGeofenceItems:
            return "Too many Polygon objects in the geofence";
        case Geofence::Result::Busy:
            return "Vehicle is busy";
        case Geofence::Result::Timeout:
            return "Request timed out";
        case Geofence::Result::InvalidArgument:
            return "Invalid argument";
        default:
            return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, Geofence::Result const& result)
{
    switch (result) {
        case Geofence::Result::Unknown:
            return str << "Result Unknown";
        case Geofence::Result::Success:
            return str << "Result Success";
        case Geofence::Result::Error:
            return str << "Result Error";
        case Geofence::Result::TooManyGeofenceItems:
            return str << "Result Too Many Geofence Items";
        case Geofence::Result::Busy:
            return str << "Result Busy";
        case Geofence::Result::Timeout:
            return str << "Result Timeout";
        case Geofence::Result::InvalidArgument:
            return str << "Result Invalid Argument";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk