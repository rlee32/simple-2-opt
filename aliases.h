#pragma once

#include "Segment.h"
#include "primitives.h"

#include <set>
#include <unordered_map>
#include <vector>

namespace aliases {

using PointContainer = std::vector<primitives::point_id_t>;
using CoordContainer = std::vector<primitives::space_t>;

using RadiusMap = std::unordered_map<Segment, primitives::length_t, Segment::Hash>;
using LengthsMap = std::unordered_map<Segment, std::vector<primitives::length_t>, Segment::Hash>;

// Must have stable iterators!
using SortedSegments = std::set<Segment, Segment::LengthComparator>;

} // namespace aliases

