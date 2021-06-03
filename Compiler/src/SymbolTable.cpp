#include "SymbolTable.h"

extern ErrorHandler error_log;
extern TypeManager type_manager;

using pair = std::pair<astring, Symbol>;
using hash_map =
    std::unordered_map<
        astring,
        Symbol,
        std::hash<astring>,
        std::equal_to<astring>,
        arena_allocator<
            std::pair<
                const astring,
                Symbol
            >
        >
    >;

SymbolTable::SymbolTable():
    global_(), table_()
{
    push_scope();
}

void SymbolTable::add_symbol(const astring& id, const SymbolType kind, const type_handle arc_type) {
    PROFILE();
    current_scope().insert(pair(id, Symbol{kind, arc_type}));
}

void SymbolTable::add_function(const astring& id, const std::vector<Arg, arena_allocator<Arg>> fn_args, const SymbolType kind, const type_handle arc_type) {
    PROFILE();
    current_scope().insert(pair(id, Symbol{kind, arc_type, fn_args}));
}

bool SymbolTable::has(const astring& id) {
    PROFILE();
    return std::ranges::any_of(table_.cbegin(), table_.cend(),
        [&](const auto& map) {return map.contains(id);}
    );
}

// return NONE if element does not exist
SymbolType SymbolTable::get_kind(const astring& id) {
    PROFILE();
    for(const auto& map : table_) {
        auto result = map.find(id);
        if(result != map.end())
            return result->second.type;
    }
    return NONE;
}

// return the type of the symbol
// if the symbol is a function then the result is the return type
type_handle SymbolTable::get_type(const astring& id) {
    PROFILE();
    for(const auto& map : table_) {
        auto result = map.find(id);
        if(result != map.end())
            return result->second.result_type;
    }
    return TYPE_UNKNOWN;
}

// assumes id is a function
u32 SymbolTable::get_num_args(const astring& id) {
    PROFILE();
    for(const auto& map : table_) {
        auto result = map.find(id);
        if(result != map.end())
            return static_cast<u32>(result->second.args.size());
    }
    return 0;
}


bool SymbolTable::scope_has(const astring& id) {
    PROFILE();
    return current_scope().contains(id);
}

bool SymbolTable::is_function(const astring& id) {
    PROFILE();
    return get_kind(id) == FUNCTION;
}

bool SymbolTable::is_variable(const astring& id) {
    PROFILE();
    return get_kind(id) == VARIABLE;
}

hash_map& SymbolTable::current_scope() {
    PROFILE();
    return table_.back();
}

void SymbolTable::push_scope() {
    PROFILE();
    table_.emplace_back(hash_map{});
}

void SymbolTable::pop_scope() {
    PROFILE();
    table_.pop_back();
}