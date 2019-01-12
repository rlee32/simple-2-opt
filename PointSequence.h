#pragma once

#include "Connection.h"
#include "Segment.h"
#include "aliases.h"
#include "primitives.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <utility> // std::swap
#include <vector>

class PointSequence
{
    using Adjacents = std::array<primitives::point_id_t, 2>;
public:
    PointSequence(const aliases::PointContainer& sequence);

    void initialize(const std::vector<primitives::point_id_t>& sequence);
    std::vector<primitives::point_id_t> points() const;

    // Mainly for debugging.
    const std::vector<primitives::point_id_t>& next() const { return m_next; }
    primitives::point_id_t next(primitives::point_id_t i) const { return m_next[i]; }
    const std::vector<Adjacents>& adjacents() const { return m_adjacents; }
    const std::vector<primitives::point_id_t>& sequence_ids() const { return m_sequence_ids; }

private:
    std::vector<Adjacents> m_adjacents;
    std::vector<primitives::point_id_t> m_next;
    std::vector<primitives::point_id_t> m_sequence_ids; // indexed by first point in the segment.

    void update_next();
    void reorder(const std::vector<Segment>& old_segments, const std::vector<Segment>& new_segments);
    primitives::point_id_t get_other(primitives::point_id_t point, primitives::point_id_t adjacent) const;
    void create_adjacency(primitives::point_id_t point1, primitives::point_id_t point2);
    void fill_adjacent(primitives::point_id_t point, primitives::point_id_t new_adjacent);
    void break_adjacency(primitives::point_id_t point1, primitives::point_id_t point2);
    void vacate_adjacent_slot(primitives::point_id_t point, primitives::point_id_t adjacent, int slot);
};
